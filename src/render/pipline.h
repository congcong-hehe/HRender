// make by hyq
// 2021/11/17

#pragma once

#include <vector>
#include <memory>
#include "context.h"
#include "../math/vec3.h"
#include "../math/vec2.h"
#include "image.h"
#include "../object/tri_mesh.h"
#include "../shader/shader.h"

class Pipeline {
public:
    Pipeline();
    ~Pipeline();
    void init(const int w, const int h);
    void setImage(int w, int h, int c);
    void vertexShader();
    void rasterAndFragmentShader();
    void renderMesh(std::shared_ptr<TriMesh> mesh);
    void drawLine(int x0, int y0, int x1, int y1, Math::Vec3f &color);

    void setVertexShader(const std::shared_ptr<VertexShader> vs) { vs_ = vs; }
    void setFragmentShader(const std::shared_ptr<FragmentShader> fs) { fs_ = fs; }
    void setPath(const std::string &path) { path_ = path; }

    // 设置context
    void setPolygonMode(Mode mode) { context_.mode = mode; }

private:
    Context context_;
    std::shared_ptr<TriMesh> mesh_; 
    Image image_;
    int w_ = 400;
    int h_ = 400;
    std::shared_ptr<VertexShader> vs_ = nullptr;
    std::shared_ptr<FragmentShader> fs_ = nullptr;
    std::string path_;

private:
    std::vector<Math::Vec2f> screen_vertices_; // 经过坐标变换到显示窗口坐标系的顶点位置
    std::vector<Math::Vec2f> screen_uvs_;  // 光栅化之后的坐标的uv值
};

Math::Vec3f barycentric(Math::Vec2f A, Math::Vec2f B, Math::Vec2f C, Math::Vec2f P);  // 计算一点在三角形中的重心坐标