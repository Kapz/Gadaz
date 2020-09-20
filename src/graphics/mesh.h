#ifndef MESH_H
#define MESH_H

#include "texture.h"
#include "shader.h"

#include "../memory/elementBuffer.h"
#include "../memory/vertexArray.h"
#include "../memory/vertexBuffer.h"
#include "../memory/vertexBufferLayout.h"

#include "../math/vector.h"

typedef struct{
    Vec3 position;
    Vec3 normal;
    Vec2 texCords;
}Vertex;

typedef struct{
    VertexArray *vao;
    VertexBuffer *vbo;
    ElementBuffer *ebo;
    Texture *textures;
    unsigned int textureCount;
    unsigned int indiceCount;
}Mesh;

Mesh *mesh_create(Vertex *vertices, int vc, unsigned int *indices, int ic, Texture *textures, int tc);
void mesh_free(Mesh *m);

void mesh_draw(Mesh *m, Shader *s);

#endif