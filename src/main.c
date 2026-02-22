#include <stdio.h>
#include "sys_call.h"
#include "utils.h"

void do_write_system_call()
{
    write_system_call();
}

void do_open_existing_system_call()
{
  // open_system_call depends on the existence of a file named "test_file.txt" in the current directory.
  // The utility function create_file can be used to create this file before calling open_system_call.
  char *filename = create_file("test.txt", (Context){.permissions = O_CREAT, .mode = 0});
  if (filename == NULL) 
  {
    printf("Failed to create the file for testing open_system_call.\n");
    return;
  }

  printf("Testing open_system_call with existing file: %s\n", filename);
  open_with_context(filename, (Context){.permissions = O_RDONLY, .mode = 0444});
  remove_file(filename);
}

void do_open_nonexisting_system_call()
{
  char *filename = {"non_existing_file.txt"};
  remove_file(filename);
  printf("Testing open_system_call with non-existing file: %s\n", filename);
  open_with_context(filename, (Context){.permissions = O_RDONLY, .mode = 0444});
}

void do_open_readwrite_as_readonly_system_call()
{
  char *filename = {"test.txt"};
  remove_file(filename);

  filename = create_file(filename, (Context){.permissions = O_CREAT, .mode = 0666});
  if (filename == NULL) 
  {
    printf("Failed to create the readwrite file.\n");
    return;
  }

  printf("Testing with existing read-write file as read-only: %s\n", filename);
  open_with_context(filename, (Context){.permissions = O_RDONLY, .mode = 0444});
  remove_file(filename);
}

void do_open_writeonly_as_readonly_system_call()
{
  char *filename = {"test.txt"};
  remove_file(filename);

  filename = create_file(filename, (Context){.permissions = O_CREAT, .mode = 0222});
  if (filename == NULL) 
  {
    printf("Failed to create the writeonly file.\n");
    return;
  }

  printf("Testing with existing write-only file as read-only: %s\n", filename);
  open_with_context(filename, (Context){.permissions = O_RDONLY, .mode = 0});
  remove_file(filename);
}


int main() {
  do_write_system_call();
  do_open_existing_system_call();
  do_open_nonexisting_system_call();
  do_open_readwrite_as_readonly_system_call();
  do_open_writeonly_as_readonly_system_call();
  return 0;
}
