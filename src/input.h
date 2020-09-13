#ifndef INPUT_H
#define INPUT_H

#include <GLFW/glfw3.h>
#include "window.h"

typedef enum Key{
    KEY_A = GLFW_KEY_A,
    KEY_B = GLFW_KEY_B,
    KEY_C = GLFW_KEY_C,
    KEY_D = GLFW_KEY_D,
    KEY_E = GLFW_KEY_E,
    KEY_F = GLFW_KEY_F,
    KEY_G = GLFW_KEY_G,
    KEY_H = GLFW_KEY_H,
    KEY_I = GLFW_KEY_I,
    KEY_J = GLFW_KEY_J,
    KEY_K = GLFW_KEY_K,
    KEY_L = GLFW_KEY_L,
    KEY_M = GLFW_KEY_M,
    KEY_N = GLFW_KEY_N,
    KEY_O = GLFW_KEY_O,
    KEY_P = GLFW_KEY_P,
    KEY_Q = GLFW_KEY_Q,
    KEY_R = GLFW_KEY_R,
    KEY_S = GLFW_KEY_S,
    KEY_T = GLFW_KEY_T,
    KEY_U = GLFW_KEY_U,
    KEY_V = GLFW_KEY_V,
    KEY_W = GLFW_KEY_W,
    KEY_X = GLFW_KEY_X,
    KEY_Y = GLFW_KEY_Y,
    KEY_Z = GLFW_KEY_Z,
    KEY_CTRL_LEFT = GLFW_KEY_LEFT_CONTROL,
    KEY_CTRL_RIGHT = GLFW_KEY_RIGHT_CONTROL,
    KEY_SPACE = GLFW_KEY_SPACE,
    KEY_SHIFT_LEFT = GLFW_KEY_LEFT_SHIFT,
    KEY_SHIFT_RIGHT = GLFW_KEY_RIGHT_SHIFT,
    KEY_ESCAPE = GLFW_KEY_ESCAPE,
    KEY_RIGHT = GLFW_KEY_RIGHT,
    KEY_LEFT = GLFW_KEY_LEFT,
    KEY_UP = GLFW_KEY_UP,
    KEY_DOWN = GLFW_KEY_DOWN
}Key;

int input_is_key_pressed(Window *win, Key k);

#endif