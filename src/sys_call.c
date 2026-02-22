#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>

#include "sys_call.h"

void write_system_call()
{
    char buf[100];

    strncpy(buf, "This is writing to screen using write() system call instead of printf library function.\n", sizeof(buf) - 1);
    buf[sizeof(buf) - 1] = '\0';
    int msg_len = strlen(buf);
    write(STDOUT_FILENO, buf, msg_len);
}

void open_system_call(char const * const filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd == -1) 
    {
        printf("Failed to open file (error: %d).\n", errno);
        perror("ERROR");
        return;
    }

    printf("File opened successfully with file descriptor: %d\n", fd);
    close(fd);
}

void open_with_context(char const * const filename, Context context)
{
    int fd = open(filename, context.permissions, context.mode);
    if (fd == -1) 
    {
        printf("Failed to open file with permissions (error: %d).\n", errno);
        perror("ERROR");
        return;
    }

    printf("File opened successfully with file descriptor: %d\n", fd);
    close(fd);
}