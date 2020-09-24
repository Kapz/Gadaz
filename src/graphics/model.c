#include "model.h"
#include "mesh.h"
#include "../math/vector.h"
#include "../engine.h"
#include <stdlib.h>

Model *model_create(const char *filePath){
    Model *m = (Model *)malloc(sizeof(Model));
    if(m == NULL){
        engine_logs("Failed to allocate memory for model\n");
        return NULL;
    }

    m->meshes = NULL;
    m->meshCount = 0;
    m->textures = NULL;
    m->textureCount = 0;

    if(load_model(m, filePath)){
        engine_logs("Failed to load model\n");
        return NULL;
    }

    return m;
}

void model_free(Model *m){
    if(m == NULL){
        return;
    }

    for(int i = 0; i < m->meshCount; i++){
        mesh_free(m->meshes[i]);
    }

    for(int i = 0; i < m->textureCount; i++){
        texture_free(m->textures[i]);
    }

    free(m);
}


void model_draw(Model *m, Shader *s){
    for(int i = 0; i < m->meshCount; i++){
        mesh_draw(m->meshes[i], s);
    }
}


static int load_model(Model *m, const char *filePath){
    struct aiScene *scene = aiImportFile(filePath, aiProcess_Triangulate | aiProcess_FlipUVs);

    if(!scene){
        engine_logs("Failed to read model data from model file\n");
        return 1;
    }

    process_node(m, scene->mRootNode, scene);
    aiReleaseImport(scene);
}

static int process_node(Model *m, struct aiNode *node, struct aiScene *scene){
    m->meshes = (Mesh **)realloc(m->meshes, m->meshCount * sizeof(Mesh *));
    if(m->meshes == NULL){
        engine_logs("Failed to allocate memory for model meshes\n");
        return NULL;
    }
    
    for(int i = 0; i < scene->mNumMeshes; i++){
        struct aiMesh *aMesh = scene->mMeshes[i];
        Mesh *mesh = process_mesh(m, aMesh, scene);

        if(mesh == NULL){
            return 1;
        }

        m->meshCount += 1;
        m->meshes[m->meshCount - 1] = mesh;
    }
}

static Mesh *process_mesh(Model *m, struct aiMesh *mesh, struct aiScene *scene){    
    Vertex *vertices = NULL;
    unsigned int *indices = NULL;
    Texture *textures = NULL;

    int vertexCount = mesh->mNumVertices;
    int faceCount = mesh->mNumFaces;
    int indiceCount = 0;
    int textureCount = 0;


    if(vertexCount > 0){
        vertices = (Vertex *)malloc(vertexCount * sizeof(Vertex));
        if(vertices == NULL){
            engine_logs("Failed to allocate memory to load mesh from model\n");
            return NULL;
        }

        for(int i = 0; i < vertexCount; i++){
            Vertex v;

            v.position.x = mesh->mVertices[i].x;
            v.position.y = mesh->mVertices[i].y;
            v.position.z = mesh->mVertices[i].z;

            v.normal.x = mesh->mNormals[i].x;
            v.normal.y = mesh->mNormals[i].y;
            v.normal.z = mesh->mNormals[i].z;

            if(mesh->mTextureCoords[0]){
                v.texCords.x = mesh->mTextureCoords[0][i].x;
                v.texCords.y = mesh->mTextureCoords[0][i].y;
            }else{
                v.texCords.x = 0;
                v.texCords.y = 0;
            }

            memcpy(&vertices[i], &v, sizeof(v));
        }
    }

    if(faceCount > 0){
        for(int i = 0; i < faceCount; i++){
            struct aiFace f = mesh->mFaces[i];
            for(int y = 0; y < f.mNumIndices; y++){
                indiceCount += 1;
                indices = realloc(indices, indiceCount * sizeof(unsigned int));
                if(indices == NULL){
                    engine_logs("Failed to allocate memory for mesh indices\n");
                    return NULL;
                }

                memcpy(&indices[indiceCount - 1], &f.mIndices[y], sizeof(unsigned int));
            }
        }
        
    }


    //TODO: Add texture parsing


    Mesh *me = mesh_create(vertices, vertexCount, indices, indiceCount, NULL, 0);
    if(me != NULL){
        if(vertices != NULL){
            free(vertices);
        }

        if(indices != NULL){
            free(indices);
        }

        if(textures != NULL){
            free(textures);
        }
    }

    return me;
}