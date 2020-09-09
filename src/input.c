#include "input.h"

int input_is_key_pressed(Window *window, Key key){
    return (glfwGetKey(window->handle, (int)key) == GLFW_PRESS);
}