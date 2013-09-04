#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <grp.h>

void print_usage(char *filename)
{
  printf("usage: %s filename\n", filename);
}

int main(int argc, char *argv[])
{
  struct stat stat_buf;
  memset(&stat_buf, 0, sizeof(stat_buf));

  if (argc < 2)
  {
    print_usage(argv[0]);
    return -1;
  }
  
  if (stat(argv[1], &stat_buf) == -1)
  {
    perror("stat");
    return -1;
  }

  struct group  *gr = getgrgid(stat_buf.st_gid);


  return 0;
}
