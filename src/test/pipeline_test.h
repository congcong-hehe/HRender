#include "../render/pipline.h"
#include <stdio.h>
#include "../shader/base_shader.h"
#include "../base.h"

using namespace std;
using namespace Math;

void pipelineTest() {
    Pipeline pipeline;

    // 绘制填充的三角形
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