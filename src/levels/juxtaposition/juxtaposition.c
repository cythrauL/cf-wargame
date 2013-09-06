#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#define edie(reason)  do{       \
                perror(reason); \
                exit(-1);       \
                }while(0);

void print_usage(char *file_name)
{
  printf("Usage: %s option\n", file_name);
}

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    print_usage(argv[0]);
    return -1;
  }

  switch(atoi(argv[1]))
  {
    case 0:
      execlp("date", "date", NULL);
      edie("case 0");
    case 1:
      execlp("echo", "echo", "[+]Called echo", NULL);
      edie("case 1");
    case 2:
      execlp("whoami", "whoami", NULL);
      edie("case 2");
    default:
      printf("[!]Invalid Argument!\n");
  }
  
  return 0;
}
