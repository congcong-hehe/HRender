// make by hyq
// 2021/11/17

#pragma once

#include <vector>
#include <memory>
#include "context.h"
#include "../math/vec3.h"
#include "../math/vec2.h"
#include "../math/vec4.h"
#include "image.h"
#include "../object/tri_mesh.h"
#include "../shader/shader.h"


// 考虑修改mesh的坐标，不产生新的坐标序列，节省内存，也就是把变换之后的顶点坐标保存到mesh的顶点中
class Pipeline {
public:
    Pipeline();
    ~Pipeline();
    void init(const int w, const int h);
    void setImage(int w, int h, int c);
    void vertexShader();
    void rasterAndFragmentShader();
    void perspectiveDivision();
    void viewPort();
    void renderMesh(std::shared_ptr<TriMesh> mesh);
    void drawLine(int x0, int y0, int x1, int y1, Math::Vec3f &color);

    void setVertexShader(const std::shared_ptr<VertexShader> vs) { vs_ = vs; }
    void setFragmentShader(const std::shared_ptr<FragmentShader> fs) { fs_ = fs; }
    void setPath(const std::string &path) { path_ = path; }

    // 设置context
    void setPolygonMode(Mode mode) { context_.mode = mode; }
    void setZtest(bool if_test) {context_.ifZtest = if_test; }

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
    std::vector<float> z_buffer_;
    std::vector<Math::Vec4f> vertices_;
    std::vector<Math::Vec3i> indices_;
};

Math::Vec3f barycentric(Math::Vec2f A, Math::Vec2f B, Math::Vec2f C, Math::Vec2f P);  // 计算一点在三角形中的重心坐标