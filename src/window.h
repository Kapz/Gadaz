#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>

typedef struct Window{
    GLFWwindow *handle;
    char *title;
}Window;

typedef enum CursorMode{
    NORMAL,
    HIDDEN,
    DISABLED
}CursorMode;


Window *window_create(char *title, int width, int height);
void window_close(Window *window);
void window_update(Window *window);

void window_make_currect(Window *window);
void window_set_cursor_mode(Window *window, CursorMode mode);
void window_set_fullscreen(Window *window, int value, int width, int height);

unsigned int window_get_width(Window *window);
unsigned int window_get_height(Window *window);
unsigned int window_get_fullscreen(Window *window);

#endif