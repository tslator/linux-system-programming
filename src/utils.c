#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include "utils.h"

char *create_file(const char *filename, Context context)
{
    int fd = open(filename, context.permissions, context.mode);
    if (fd == -1) 
    {
        perror("Failed to create file");
        return NULL;
    }

    close(fd);
    return strdup(filename);
}

void remove_file(const char *filename)
{
    if (unlink(filename) == -1) 
    {
        perror("Failed to remove file");
    }
}