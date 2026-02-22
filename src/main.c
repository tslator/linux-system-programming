#include <stdio.h>
#include "sys_call.h"
#include "utils.h"

void do_write_system_call()
{
    write_system_call();
}

void do_open_system_call()
{
  // open_system_call depends on the existence of a file named "test_file.txt" in the current directory.
  // The utility function create_file can be used to create this file before calling open_system_call.
  char *filename = create_file("test.txt", (Context){.permissions = O_CREAT | O_RDWR, .mode = 0644});
  if (filename == NULL) 
  {
    printf("Failed to create the file for testing open_system_call.\n");
    return;
  }

  printf("Testing open_system_call with existing file: %s\n", filename);
  open_system_call(filename);

  printf("Removing filename: %s\n", filename);
  remove_file(filename);

  printf("Testing open_system_call with non-existing file: %s\n", filename);
  open_system_call(filename);

  printf("Cleaning up filename: %s\n", filename);
  remove_file(filename);
}

void do_open_permissions_system_call()
{
  remove_file("test.txt");

  char *filename = create_file("test.txt", (Context){.permissions = O_CREAT | O_RDWR, .mode = 0644});
  if (filename == NULL) 
  {
    printf("Failed to create the readwrite file.\n");
    return;
  }

  printf("Testing with existing read-write file as read-only: %s\n", filename);
  open_with_context(filename, (Context){.permissions = O_RDONLY, .mode = 0444});

  remove_file(filename);

  filename = create_file("test.txt", (Context){.permissions = O_CREAT | O_WRONLY, .mode = 0222});
  if (filename == NULL) 
  {
    printf("Failed to create the writeonly file.\n");
    return;
  }

  printf("Testing with existing write-only file as read-only: %s\n", filename);
  open_with_context(filename, (Context){.permissions = O_RDONLY, .mode = 0444});

  remove_file(filename);
}


int main() {
  // do_write_system_call();
  // do_open_system_call();
  do_open_permissions_system_call();
  return 0;
}
