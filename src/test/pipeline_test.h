#include "../render/pipline.h"
#include <stdio.h>
#include "../shader/base_shader.h"
#include "../base.h"
#include "../render/texture.h"

using namespace std;
using namespace Math;

void drawCube() {
    Pipeline pipeline;

    pipeline.init(400, 400);
    pipeline.setPath(current_path + "result/cube.png");
    
    Texture texture2;
    texture2.load(current_path + "assets/awesomeface.png");
    texture2.setMode(TextureMode::LINEAR);

    Texture texture1;
    texture1.load(current_path + "assets/container.jpg");
    texture1.setMode(TextureMode::LINEAR);

    Mat4 rotateX = getRotate(AXIS::X, 1.0f);
    Mat4 rotateY = getRotate(AXIS::Y, 1.0f);

    shared_ptr<VertexShader> vs = make_shared<BaseVSShader>();
    shared_ptr<FragmentShader> fs = make_shared<BaseFSShader>();
    dynamic_pointer_cast<BaseVSShader>(vs)->rotate = rotateX * rotateY;
    dynamic_pointer_cast<BaseFSShader>(fs)->texture1 = &texture1; // 纹理绑定
    dynamic_pointer_cast<BaseFSShader>(fs)->texture2 = &texture2; // 纹理绑定
    pipeline.setVertexShader(vs);
    pipeline.setFragmentShader(fs);

    shared_ptr<TriMesh> mesh = make_shared<TriMesh>();
    vector<Vec3i> vertex_indices = {
        Vec3i(0, 1, 2),
        Vec3i(3, 4, 5),
        Vec3i(6, 7, 8),
        Vec3i(9, 10, 11),
        Vec3i(12, 13, 14),
        Vec3i(15, 16, 17),
        Vec3i(18, 19, 20),
        Vec3i(21, 22, 23),
        Vec3i(24, 25, 26),
        Vec3i(27, 28, 29),
        Vec3i(30, 31, 32),
        Vec3i(33, 34, 35)
    };
    mesh->moveVertexIndices(vertex_indices);
    vector<Vec3f> vertices = {
        Vec3f(-5.0f, -5.0f, -5.0f),
        Vec3f( 5.0f, -5.0f, -5.0f),
        Vec3f( 5.0f,  5.0f, -5.0f),
        Vec3f( 5.0f,  5.0f, -5.0f),
        Vec3f(-5.0f,  5.0f, -5.0f),
        Vec3f(-5.0f, -5.0f, -5.0f),

        Vec3f(-5.0f, -5.0f,  5.0f),
        Vec3f( 5.0f, -5.0f,  5.0f),
        Vec3f( 5.0f,  5.0f,  5.0f),
        Vec3f( 5.0f,  5.0f,  5.0f),
        Vec3f(-5.0f,  5.0f,  5.0f),
        Vec3f(-5.0f, -5.0f,  5.0f),

        Vec3f(-5.0f,  5.0f,  5.0f),
        Vec3f(-5.0f,  5.0f, -5.0f),
        Vec3f(-5.0f, -5.0f, -5.0f),
        Vec3f(-5.0f, -5.0f, -5.0f),
        Vec3f(-5.0f, -5.0f,  5.0f),
        Vec3f(-5.0f,  5.0f,  5.0f),

        Vec3f( 5.0f,  5.0f,  5.0f),
        Vec3f( 5.0f,  5.0f, -5.0f),
        Vec3f( 5.0f, -5.0f, -5.0f),
        Vec3f( 5.0f, -5.0f, -5.0f),
        Vec3f( 5.0f, -5.0f,  5.0f),
        Vec3f( 5.0f,  5.0f,  5.0f),

        Vec3f(-5.0f, -5.0f, -5.0f),
        Vec3f( 5.0f, -5.0f, -5.0f),
        Vec3f( 5.0f, -5.0f,  5.0f),
        Vec3f( 5.0f, -5.0f,  5.0f),
        Vec3f(-5.0f, -5.0f,  5.0f),
        Vec3f(-5.0f, -5.0f, -5.0f),

        Vec3f(-5.0f,  5.0f, -5.0f),
        Vec3f( 5.0f,  5.0f, -5.0f),
        Vec3f( 5.0f,  5.0f,  5.0f),
        Vec3f( 5.0f,  5.0f,  5.0f),
        Vec3f(-5.0f,  5.0f,  5.0f),
        Vec3f(-5.0f,  5.0f, -5.0f)

    };
    mesh->moveVertices(vertices);
    vector<Vec2f> uvs = {
        Vec2f( 0.0f, 0.0f),
        Vec2f( 1.0f, 0.0f),
        Vec2f( 1.0f, 1.0f),
        Vec2f( 1.0f, 1.0f),
        Vec2f( 0.0f, 1.0f),
        Vec2f( 0.0f, 0.0f),

        Vec2f( 0.0f, 0.0f),
        Vec2f( 1.0f, 0.0f),
        Vec2f( 1.0f, 1.0f),
        Vec2f( 1.0f, 1.0f),
        Vec2f( 0.0f, 1.0f),
        Vec2f( 0.0f, 0.0f),

        Vec2f( 1.0f, 0.0f),
        Vec2f( 1.0f, 1.0f),
        Vec2f( 0.0f, 1.0f),
        Vec2f( 0.0f, 1.0f),
        Vec2f( 0.0f, 0.0f),
        Vec2f( 1.0f, 0.0f),

        Vec2f( 1.0f, 0.0f),
        Vec2f( 1.0f, 1.0f),
        Vec2f( 0.0f, 1.0f),
        Vec2f( 0.0f, 1.0f),
        Vec2f( 0.0f, 0.0f),
        Vec2f( 1.0f, 0.0f),

        Vec2f( 0.0f, 1.0f),
        Vec2f( 1.0f, 1.0f),
        Vec2f( 1.0f, 0.0f),
        Vec2f( 1.0f, 0.0f),
        Vec2f( 0.0f, 0.0f),
        Vec2f( 0.0f, 1.0f),

        Vec2f( 0.0f, 1.0f),
        Vec2f( 1.0f, 1.0f),
        Vec2f( 1.0f, 0.0f),
        Vec2f( 1.0f, 0.0f),
        Vec2f( 0.0f, 0.0f),
        Vec2f( 0.0f, 1.0f)
    };
    mesh->moveUvs(uvs);
    pipeline.setPolygonMode(Mode::FILL);
    pipeline.setZtest(true);
    pipeline.renderMesh(mesh);
}