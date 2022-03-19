#include "../render/pipline.h"
#include <stdio.h>
#include "../shader/base_shader.h"
#include "../base.h"
#include "../render/texture.h"

using namespace std;
using namespace Math;

void drawTriangleTexture() {
    Pipeline pipeline;

    pipeline.init(400, 400);
    pipeline.setPath(current_path + "result/texture.png");
    
    Texture texture;
    texture.load(current_path + "assets/wall.jpg");
    texture.setMode(TextureMode::LINEAR);

    shared_ptr<VertexShader> vs = make_shared<BaseVSShader>();
    shared_ptr<FragmentShader> fs = make_shared<BaseFSShader>();
    dynamic_pointer_cast<BaseFSShader>(fs)->texture = &texture; // 纹理绑定
    pipeline.setVertexShader(vs);
    pipeline.setFragmentShader(fs);

    shared_ptr<TriMesh> mesh = make_shared<TriMesh>();
    vector<Vec3i> vertex_indices = {Vec3i(0, 1, 2)};
    mesh->moveVertexIndices(vertex_indices);
    vector<Vec3f> vertices = {Vec3f(-0.5f, -0.5f, 0), Vec3f(0.5f, -0.5f, 0), Vec3f(0.0f, 0.5f, 0)};
    mesh->moveVertices(vertices);
    vector<Vec2f> uvs = {Vec2f(0.0f, 0.0f), Vec2f(1.0f, 0.0f), Vec2f(0.5f, 1.0f)};
    mesh->moveUvs(uvs);
    DEBUG
    pipeline.setPolygonMode(Mode::FILL);
    pipeline.renderMesh(mesh);
}

void drawTriangle()
{
    Pipeline pipeline;

    // 绘制三角形
    { 
        pipeline.init(400, 400);
        pipeline.setPath(current_path + "result/wire.png");
        
        shared_ptr<VertexShader> vs = make_shared<BaseVSShader>();
        shared_ptr<FragmentShader> fs = make_shared<BaseFSShader>();
        pipeline.setVertexShader(vs);
        pipeline.setFragmentShader(fs);

        shared_ptr<TriMesh> mesh = make_shared<TriMesh>();
        vector<Vec3i> vertex_indices = {Vec3i(0, 1, 2)};
        mesh->setVertexIndices(vertex_indices);
        vector<Vec3f> vertices = {Vec3f(-0.5f, -0.5f, 0), Vec3f(0.5f, -0.5f, 0), Vec3f(0.0f, 0.5f, 0)};
        mesh->setVertices(vertices);
        vector<Vec3f> colors = {Vec3f(1.0f, 0.0f, 0.0f), Vec3f(0.0f, 1.0f, 0.0f), Vec3f(0.0f, 0.0f, 1.0f)};
        mesh->setColors(colors);

        pipeline.setPolygonMode(Mode::WIRE);
        pipeline.renderMesh(mesh);
    }
}