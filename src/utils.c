#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include "utils.h"

static char *create_file_with_permissions(const char *filename, int permissions, mode_t mode)
{
    int fd = open(filename, permissions, mode);
    if (fd == -1) 
    {
        perror("Failed to create file");
        return NULL;
    }

    close(fd);
    return strdup(filename);
}

// char *create_readonly_file(const char *filename)
// {
//     return create_file_with_permissions(filename, O_CREAT | O_RDONLY, 0644);
// }

// char *create_readwrite_file(const char *filename)
// {
//     return create_file_with_permissions(filename, O_CREAT | O_RDWR, 0644);
// }

// char *create_writeonly_file(const char *filename)
// {
//     return create_file_with_permissions(filename, O_CREAT | O_WRONLY, 0644);
// }

// char *create_executable_file(const char *filename)
// {
//     return create_file_with_permissions(filename, O_CREAT | O_RDWR, 0755);
// }

char *create_file(const char *filename, Context context)
{
    return create_file_with_permissions(filename, context.permissions, context.mode);
}

void remove_file(const char *filename)
{
    if (unlink(filename) == -1) 
    {
        perror("Failed to remove file");
    }
}