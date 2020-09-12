#include "VertexBufferLayout.h"
#include "../engine.h"
#include <stdlib.h>

VertexBufferLayout *vb_layout_create(void){
    VertexBufferLayout *layout;

    layout = (VertexBufferLayout *)malloc(sizeof(VertexBufferLayout));
    if(layout == NULL){
        engine_logs("Failed to allocate memory for vertex buffer layout\n");
        return NULL;
    }

    layout->elements = NULL;
    layout->elementCount = 0;

    return layout;
}

int vb_layout_push_element(VertexBufferLayout *layout, GLenum type, int amount, GLboolean normalized){
    layout->elementCount += 1;
    Element *buffer = (Element *)realloc(layout->elements, (sizeof(Element) * layout->elementCount));

    if(buffer == NULL){
        engine_logs("Failed to reallocate memory for layout\n");
        return 1;
    }else{
        layout->elements = buffer;
    }

    Element *element = (layout->elements + (layout->elementCount - 1));
    element->type = type;
    element->count = amount;
    element->normalized = normalized;

    return 0;
}

void vb_layout_free(VertexBufferLayout *layout){
    if(layout->elements != NULL){
        free(layout->elements);
    }

    if(layout != NULL){
        free(layout);
    }
}