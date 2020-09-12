#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>

typedef struct Window{
    GLFWwindow *handle;
}Window;

typedef enum CursorMode{
    NORMAL,
    HIDDEN,
    DISABLED
}CursorMode;


Window *window_create(char *title, int width, int height);
void window_free(Window *win);

void window_close(Window *win);
void window_update(Window *win);

void window_make_currect(Window *win);
void window_set_cursor_mode(Window *win, CursorMode mode);

unsigned int window_get_width(Window *win);
unsigned int window_get_height(Window *win);
unsigned int window_get_fullscreen(Window *win);

int window_should_close(Window *win);

#endif