#include "input.h"

int input_is_key_pressed(Window *win, Key k){
    return (glfwGetKey(win->handle, (int)k) == GLFW_PRESS);
}