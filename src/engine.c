#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "engine.h"

int engine_init(void){
    glfwInit();
    debugOutput = stdout;
}

int engine_init_gl(void){
    glewExperimental = GL_TRUE;
    GLenum status = glewInit();

    if(status != GLEW_OK){
        engine_logs(glewGetErrorString(status));
        return 1;
    }

    return 0;
}

int engine_cleanup(void){
    // TODO: De-initialize glew?
    glfwTerminate();
}

int engine_logs(const char *data){
    return fputs(data, debugOutput);
}

void engine_set_debug_fd(FILE *fd){
    debugOutput = fd;
}