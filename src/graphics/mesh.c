#include "mesh.h"
#include "../engine.h"
#include <stdlib.h>
#include <stddef.h>

Mesh *mesh_create(Vertex *vertices, int vc, unsigned int *indices, int ic, Texture *textures, int tc){
    Mesh *m = (Mesh *)malloc(sizeof(Mesh));
    if(m == NULL){
        engine_logs("Failed to allocate memory for mesh\n");
        return NULL;
    }

    VertexArray *vao = va_create();
    if(vao == NULL){
        return NULL;
    }
    va_bind(vao);

    VertexBuffer *vbo = vb_create(vc * sizeof(Vertex), vertices);
    if(vbo == NULL){
        return NULL;
    }
    vb_bind(vbo);

    ElementBuffer *ebo = eb_create(ic * sizeof(unsigned int), indices);
    if(ebo == NULL){
        return NULL;
    }
    eb_bind(ebo);

    // We dont use a layout because we have custom struct offsets
    va_attrib_pointer(vao, 0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
    va_attrib_pointer(vao, 1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, normal));
    va_attrib_pointer(vao, 2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, texCords));

    m->vao = vao;
    m->vbo = vbo;
    m->ebo = ebo;

    if(textures != NULL){
        m->textures = textures;
        m->textureCount = tc;
    }else{
        m->textures = NULL;
        m->textureCount = 0;
    }

    m->indiceCount = ic;
    return m;
}

void mesh_free(Mesh *m){
    if(m->vbo != NULL){
        vb_free(m->vbo);
    }

    if(m->vao != NULL){
        va_free(m->vao);
    }

    if(!m->ebo){
        eb_free(m->ebo);
    }

    free(m);
}


void mesh_draw(Mesh *m, Shader *s){
    shader_bind(s);

    if(m->textures != NULL){
        texture_bind_to_slot(m->textures, 0);
        texture_bind(m->textures);
    }

    va_bind(m->vao);
    glDrawElements(GL_TRIANGLES, m->indiceCount, GL_UNSIGNED_INT, 0);
    va_unbind(m->vao);

    shader_unbind(s);
}