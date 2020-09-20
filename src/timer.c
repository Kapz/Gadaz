#include "timer.h"
#include "engine.h"
#include <stdlib.h>
#include <GLFW/glfw3.h>

Timer *timer_create(void){
    Timer *t;
    t = (Timer *)malloc(sizeof(Timer));
    
    if(t == NULL){
        engine_logs("Failed to allocate memory for Timer\n");
        return NULL;
    }
    
    t->lastTime = 0;
    
    return t;
}

void timer_free(Timer *t){
    if(t != NULL){
        free(t);
    }
}

void timer_start(Timer *t){
    t->lastTime = glfwGetTime();
}

double timer_restart(Timer *t){
    double delta = glfwGetTime() - t->lastTime;
    t->lastTime = glfwGetTime();
    return delta;
}

double timer_get_elapsed_time(Timer *t){
    return glfwGetTime() - t->lastTime;
}

double timer_stop(Timer *t){
    double delta = timer_get_elapsed_time(t);
    t->lastTime = 0;
    return delta;
}