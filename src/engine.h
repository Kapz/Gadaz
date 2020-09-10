#ifndef ENGINE_H
#define ENGINE_H

#include <stdio.h>

#define ENGINE_SUCCES 0
#define ENGINE_ERROR 1

#define ENGINE_TRUE 1
#define ENGINE_FALSE 0

/* File descriptor fot debug output */
static FILE *debugOutput;

int init_engine(void);
int engine_init_gl(void);
int cleanup_engine(void);
int engine_logs(const char *data);

void engine_set_debug_fd(FILE *fd);

#endif