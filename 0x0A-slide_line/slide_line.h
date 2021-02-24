#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stddef.h>

#define SLIDE_LEFT 'L'
#define SLIDE_RIGHT 'R'

int slide_line(int *line, size_t size, int direction);
void slide_num(int *line, size_t position, size_t size, int direction);
void merge(int *line, size_t position, size_t size, int direction);

#endif
