#include "timer.h"
#include <stdlib.h>
#include <GLFW/glfw3.h>

Timer *timer_create(void){
    Timer *timer;
    timer = (Timer *)malloc(sizeof(Timer));
    /* No malloc check needed, we return instantly anyway*/
    return timer;
}

void timer_free(Timer *timer){
    if(timer != NULL){
        free(timer);
    }
}

void timer_start(Timer *timer){
    timer->lastTime = glfwGetTime();
}

double timer_restart(Timer *timer){
    double delta = glfwGetTime() - timer->lastTime;
    timer->lastTime = glfwGetTime();
    return delta;
}

double timer_get_elapsed_time(Timer *timer){
    return glfwGetTime() - timer->lastTime;
}

double timer_stop(Timer *timer){
    double delta = timer_get_elapsed_time(timer);
    timer->lastTime = 0;
    return delta;
}