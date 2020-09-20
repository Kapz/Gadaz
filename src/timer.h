#ifndef TIMER_H
#define TIMER_H

typedef struct{
    double lastTime;
}Timer;

Timer *timer_create(void);
void timer_free(Timer *t);

void timer_start(Timer *t);
double timer_restart(Timer *t);
double timer_get_elapsed_time(Timer *t);
double timer_stop(Timer *t);

#endif