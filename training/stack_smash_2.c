#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

#define BOOL char


/*Mock struct*/
typedef struct data
{
  char string[16];
  char *extra;
  BOOL big_string;
} data;

/*lazy global struct*/
data my_data;

void goal_function()
{
  printf("Winner!\n");
  return;
}

/*mock function*/
void play_with_data()
{
  printf("If I were a string, I'd say %s\n", my_data.big_string? my_data.extra : my_data.string);
  return;
}

/*Read in data, assign data to our struct, account for large values
 *by moving it into a pre-allocated block.
 *dodgy for lots of reasons...
 *I see code like this ALL the time...*/
void reader()
{
  int fd;

  my_data.extra = (char *)malloc(256);
  my_data.big_string = 0;
  /*Open file*/
  if ((fd = open("/tmp/data", O_RDONLY)) == -1)
  {
    perror("open");
    exit(-1);
  }

  /*read in data, using a not-so-smart pointer*/
  int offset = 0;
  char *smart_pointer = my_data.string;
  while (read(fd, smart_pointer + offset, 4) == 4)
  {
    offset+=4;
    if (offset > 16)
    {
      memcpy(&my_data.string, my_data.extra, 16);
      smart_pointer = my_data.extra + offset;
      my_data.big_string = 1;
    }
  }
  return;
}

/*main func*/
int main()
{
  reader();
  play_with_data();
  return 0;
}
