#include <stdio.h>
#include <GLFW/glfw3.h>

#include "engine.h"

int engine_init(void){
    glfwInit();

    debugOutput = stdout;
}

int engine_cleanup(void){
    glfwTerminate();
}

int engine_logs(const char *data){
    return fputs(data, debugOutput);
}

void engine_set_debug_fd(FILE *fd){
    debugOutput = fd;
}