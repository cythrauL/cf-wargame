#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>

int printer(char *filename)
{
  int fd;
  unsigned char data_buf[36];
  memset(data_buf, 0, sizeof(data_buf));
  
  if((fd = open(filename, 0)) < 0)
  {
    perror("open");
  }

  if (read(fd, data_buf, 36) < 0)
  {
    perror("read");
    return -1;
  }

  int8_t str_len = data_buf[0];
  
  if (str_len > 35)
  {
    printf("[!]String is too long...\n");
    return -1;
  }
 
  if (write(1, data_buf+1, data_buf[0]) < 0)
  {
    perror("write");
    return -1;
  }
  return 0;
}

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    printf("[!]Usage: %s filename\n", argv[0]);
    return 0;
  }
  printer(argv[1]);
  return 0;
}
