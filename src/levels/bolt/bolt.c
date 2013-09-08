#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

void print_usage(char *filename)
{
  printf("[!]Usage: %s filename\n", filename);
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

  if((stat_buf.st_uid == 0) || (stat_buf.st_uid == getuid()))
  {
    printf("[!]Can't call setuid 0 binaries, or binaries created by you.\n");
    return -1;
  }
  else
  {
    execl(argv[1], argv[1], NULL);
  }

  return 0;
}
