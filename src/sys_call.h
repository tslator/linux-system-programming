#include <fcntl.h>
#include "utils.h"

#ifndef SYS_CALL_H
#define SYS_CALL_H
void write_system_call();
void open_system_call(char const * const filename);
void open_with_context(char const * const filename, Context context);
#endif