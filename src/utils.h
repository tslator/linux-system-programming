#include <fcntl.h>

#ifndef UTILS_H
#define UTILS_H
typedef struct {
    int permissions;
    mode_t mode;
} Context;

char *create_file(const char *filename, Context context);
void remove_file(const char *filename);

#endif