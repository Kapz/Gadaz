#ifndef TIMER_H
#define TIMER_H

typedef struct Timer{
    double lastTime;
}Timer;

Timer *timer_create(void);
void timer_free(Timer *timer);

void timer_start(Timer *timer);
double timer_restart(Timer *timer);
double timer_get_elapsed_time(Timer *timer);
double timer_stop(Timer *timer);

#endif