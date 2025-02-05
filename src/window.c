#include <stdlib.h>
#include <string.h>

#include "engine.h"
#include "window.h"

Window *window_create(char *title, int width, int height){
    Window *win;
    win = (Window *)malloc(sizeof(Window));

    if(win == NULL){
        engine_logs("Failed to allocate memory for window object\n");
        return NULL;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    win->handle = glfwCreateWindow(width, height, title, NULL, NULL);

    glfwSetFramebufferSizeCallback(win->handle, frame_buffer_callback);

    /* Automatically make new window currect */
    glfwMakeContextCurrent(win->handle);
    return win;
}

void window_free(Window *window){
    if(window != NULL){
        free(window);
    }
}

void window_close(Window *window){
    glfwDestroyWindow(window->handle);
}

void window_update(Window *window){
    glfwSwapBuffers(window->handle);
    glfwPollEvents();
}


void window_make_currect(Window *window){
    glfwMakeContextCurrent(window->handle);
}

void window_set_cursor_mode(Window *window, CursorMode mode){
    switch(mode){
        case NORMAL: glfwSetInputMode(window->handle, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        case HIDDEN: glfwSetInputMode(window->handle, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
        case DISABLED: glfwSetInputMode(window->handle, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        default: break;
    }
}

// TODO: Fix this function. Glitched?
void window_set_fullscreen(Window *window, int value, int width, int height){
    if(value){
        glfwSetWindowMonitor(window->handle, glfwGetPrimaryMonitor(), 0, 0, width, height, GLFW_DONT_CARE);
    }else{
        glfwSetWindowMonitor(window->handle, NULL, 0, 0, width, height, GLFW_DONT_CARE);
    }
}


unsigned int window_get_width(Window *win){
    int width;
    glfwGetWindowSize(win->handle, &width, NULL);
    return width;
}

unsigned int window_get_height(Window *win){
    int height;
    glfwGetWindowSize(win->handle, NULL, &height);
    return height;
}

int window_should_close(Window *win){
    return glfwWindowShouldClose(win->handle);
}

static void frame_buffer_callback(GLFWwindow *window, int width, int height){
    glViewport(0, 0, width, height);
}