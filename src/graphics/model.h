#ifndef MODEL_H
#define MODEL_H

#include "mesh.h"
#include "texture.h"
#include "shader.h"

#include <assimp/types.h>
#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

typedef struct{
    Mesh **meshes;
    unsigned int meshCount;
    Texture **textures;
    unsigned int textureCount;
}Model;

Model *model_create(const char *filePath);
void model_free(Model *m);

void model_draw(Model *m, Shader *s);

static int load_model(Model *m, const char *filePath);
static int process_node(Model *m, struct aiNode *node, struct aiScene *scene);
static Mesh *process_mesh(Model *m, struct aiMesh *mesh, struct aiScene *scene);

#endif