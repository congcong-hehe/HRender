// make by hyq
// 2021/11/17

#pragma once

#include "../math/vec3f.h"
#include "../math/vec3i.h"
#include "../math/vec2f.h"
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
    
    inline void setVertices(const std::vector<Math::Vec3f> &vertices) { vertices_ = vertices; }
    inline void setVertexIndices(const std::vector<Math::Vec3i> &indices) { vertex_indices_ = indices; }
    inline void setNormalIndices(const std::vector<Math::Vec3i> &indices) { normal_indices_ = indices; }
    inline void setUVIndices(const std::vector<Math::Vec3i> &indices) { uv_indices_ = indices; }
    inline std::vector<Math::Vec3f>  getVertices() { return vertices_; }
    inline std::vector<Math::Vec3i> getVertexIndices() { return vertex_indices_; }
    inline std::vector<Math::Vec3i> getNormalIndices() { return normal_indices_; }
    inline std::vector<Math::Vec3i> getUVIndices() { return uv_indices_; }

private:
    std::vector<Math::Vec3i> vertex_indices_;
    std::vector<Math::Vec3i> normal_indices_;
    std::vector<Math::Vec3i> uv_indices_;
    std::vector<Math::Vec3f> vertices_;
    std::vector<Math::Vec3f> normals_;
    std::vector<Math::Vec2f> uvs_;
};