#include <fcntl.h>

#ifndef UTILS_H
#define UTILS_H
typedef struct {
    int permissions;
    mode_t mode;
} Context;

// char *create_readonly_file(const char *filename);
// char *create_readwrite_file(const char *filename);
// char *create_writeonly_file(const char *filename);
// char *create_executable_file(const char *filename);

char *create_file(const char *filename, Context context);
void remove_file(const char *filename);

#endif