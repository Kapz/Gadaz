#include "engine.h"

#include <GLFW/glfw3.h>

int init_engine(){
    glfwInit();
}

int cleanup_engine(){
    glfwTerminate();
}