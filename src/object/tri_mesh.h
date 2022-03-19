// make by hyq
// 2021/11/17

#pragma once

#include "../math/vec3.h"
#include "../math/vec2.h"
#include <vector>
#include <string>

// 有的时候只需要使用一个顶点属性，但是类中有三个变量，肯定需要占用一定的内存
// 如何在类的外面定制化类

class TriMesh {
public:
    TriMesh();
    ~TriMesh();
    bool empty();
    void loadObj();
    
    // 当参数为const的时候，使用move不会发生转移，而是拷贝
    void setVertices(const std::vector<Math::Vec3f> &vertices) { vertices_ = vertices; }
    void setColors(const std::vector<Math::Vec3f> &colors) { colors_ = colors; }
    void setUvs(const std::vector<Math::Vec2f> &uvs) { uvs_ = uvs; }
    void setVertexIndices(const std::vector<Math::Vec3i> &indices) { vertex_indices_ = indices; }

    void moveVertices(std::vector<Math::Vec3f> &vertices) { vertices_ = move(vertices); }
    void moveColors(std::vector<Math::Vec3f> &colors) { colors_ = move(colors); }
    void moveUvs(std::vector<Math::Vec2f> &uvs) { uvs_ = move(uvs); }
    void moveVertexIndices(std::vector<Math::Vec3i> &indices) { vertex_indices_ = move(indices); }

    std::vector<Math::Vec3f>& getVertices() { return vertices_; }
    std::vector<Math::Vec3f>& getColors() { return colors_; }
    std::vector<Math::Vec2f>& getUvs() { return uvs_; }
    std::vector<Math::Vec3i>& getVertexIndices() { return vertex_indices_; }

private:
    std::vector<Math::Vec3i> vertex_indices_;
    std::vector<Math::Vec3f> vertices_;
    std::vector<Math::Vec3f> normals_;
    std::vector<Math::Vec2f> uvs_;
    std::vector<Math::Vec3f> colors_;
};