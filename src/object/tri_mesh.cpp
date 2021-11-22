// make by hyq
// 2021/11/17

#include "tri_mesh.h"

using namespace std;
using namespace Math;

TriMesh::TriMesh() {

}

TriMesh::~TriMesh() {

}

bool TriMesh::empty() {
    return vertex_indices_.empty() || vertices_.empty();
}

void TriMesh::loadObj() {
    
}

