#ifndef VERTEX_BUFFER_LAYOUT_H
#define VERTEX_BUFFER_LAYOUT_H

#include <GL/glew.h>

typedef struct Element{
    GLenum type;
    int count;
    GLboolean normalized;
}Element;

typedef struct VertexBufferLayout{
    Element *elements;
    int elementCount;
}VertexBufferLayout;


VertexBufferLayout *vb_layout_create(void);
int vb_layout_push_element(VertexBufferLayout *layout, GLenum type, int amount, GLboolean normalized);
void vb_layout_free(VertexBufferLayout *layout);
#endif