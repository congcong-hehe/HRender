// make by hyq
// 2021/11/17

#include "pipline.h"
#include <algorithm>
#include "../base.h"
#include "../shader/interpolation_shader.h"

using namespace std;
using namespace Math;

Pipeline::Pipeline() {
    
}

Pipeline::~Pipeline() {

}

void Pipeline::init(const int w, const int h) {
    w_ = w;
    h_ = h;
    setImage(w, h, 3);
}

void Pipeline::setImage(int w, int h, int c) {
    image_.setHeight(h);
    image_.setWidth(w);
    image_.setChannels(c);
    image_.init();
}

void Pipeline::vertexShader() {
    auto vs = dynamic_pointer_cast<InterVSShader>(vs_);

    auto &vertices = mesh_->getVertices();
    screen_vertices_.resize(vertices.size());
    for(int j = 0; j < vertices.size(); ++j) {
        Vec3f &vertex = vertices[j];
        // 顶点着色器
        vs->pos = vertex;
        vs->execute();

        // 视口变换
        float y = (vs->gl_position.x + 1) / 2.0f * w_;
        float x = (vs->gl_position.y + 1) / 2.0f * h_;
        // opengl的窗口的图片的坐标是反的，所以需要颠倒一下
        x = h_ - x;
        screen_vertices_[j] = Vec2f(x, y);
    }

}

// 计算一个点在三角形中的重心坐标
// https://zhuanlan.zhihu.com/p/65495373
Vec3f barycentric(Vec2f A, Vec2f B, Vec2f C, Vec2f P) {
    Vec3f v1(B.x - A.x, C.x - A.x, A.x - P.x);
    Vec3f v2(B.y - A.y, C.y - A.y, A.y - P.y);
    Vec3f u = cross(v1, v2);
    if(abs(u.z) > 1e-2)
        return Vec3f(1.0f - (u.x + u.y) / u.z, u.x / u.z, u.y / u.z);
    else return Vec3f(-1, 1, 1);
}

// 设置深度测试在片段着色器之前执行，在光栅化阶段
// 创建二维三角形的包围盒，对于包围盒中的像素，通过重心坐标判断是否在三角形中
// 光栅化的对象是每一个三角形，而片段着色器是对于三角形中的每一个像素
// 如果要将光栅化阶段和片段着色器分开，那么就必须存储光栅化后得到的像素， 那么存储就需要一笔开销
// https://developer.nvidia.com/content/life-triangle-nvidias-logical-pipeline 
// 从上面的链接可以看出光栅化之后，片段着色器和其在一个模块中分为多个运行
void Pipeline::rasterAndFragmentShader() {
    auto fs = dynamic_pointer_cast<InterFSShader>(fs_);

    auto &vertex_indices = mesh_->getVertexIndices();
    for(int j = 0; j < vertex_indices.size(); ++j) {
        auto &vertex_indice = vertex_indices[j];

        Vec2f box_min(static_cast<float>(image_.getWidth() - 1), static_cast<float>(image_.getWidth() - 1));
        Vec2f box_max(0.f, 0.f);

        // 计算包围盒
        for(int k = 0; k < 3; ++k) {
            box_min.x = min(box_min.x, screen_vertices_[vertex_indice.vec[k]].x);
            box_min.y = min(box_min.y, screen_vertices_[vertex_indice.vec[k]].y);
            box_max.x = max(box_max.x, screen_vertices_[vertex_indice.vec[k]].x);
            box_max.y = max(box_max.y, screen_vertices_[vertex_indice.vec[k]].y);
        }

        Vec2f &A = screen_vertices_[vertex_indice.x];
        Vec2f &B = screen_vertices_[vertex_indice.y];
        Vec2f &C = screen_vertices_[vertex_indice.z];

        // 对包围盒中的每一个像素处理
        for(int x = static_cast<int>(box_min.x); x <= box_max.x; ++x) {
            for(int y = static_cast<int>(box_min.y); y <= box_max.y; ++y) {
                Vec2f P = Vec2f(static_cast<float>(x), static_cast<float>(y));

                Vec3f bc = barycentric(A, B, C, P);
                if(bc.x < 0 || bc.y < 0 || bc.z < 0) continue;  // 点不在三角形中

                Vec3f color;
                color += mesh_->getColors()[vertex_indice.x] * bc.x;
                color += mesh_->getColors()[vertex_indice.y] * bc.y;
                color += mesh_->getColors()[vertex_indice.z] * bc.z;

                // 顶点着色器
                fs->color = color;
                fs->execute();

                image_.setColor(x, y, fs->frag_color);
            }
        }
    }
}


void Pipeline::renderMesh(shared_ptr<TriMesh> mesh) {
    mesh_ = mesh;
    vertexShader();
    rasterAndFragmentShader();

    image_.write(path_);
}