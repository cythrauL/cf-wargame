#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

#define JACKPOT "/level_up"
#define PASS_LEN 12

#define edie(reason)  do{ perror(reason);      \
                          exit(-1);            \
                        }while(0);

int pass_gen(unsigned char *password)
{
  int fd;
  if((fd = open("/dev/urandom", O_RDONLY)) < 0)
  {
    edie("open");
  }
  if(read(fd, password, PASS_LEN) != PASS_LEN)
  {
    edie("read");
  }
  int c;
  for(c = 0; c < PASS_LEN - 1; c++)
  {
    password[c] = password[c] % 16;
    if (password[c] < 10)
    {
      password[c] = password[c] + 48;
    }
    else
    {
      password[c] = password[c] + 97;
    }
  }
  password[PASS_LEN - 1] = '\x00';
  return 0;
}

void print_usage(char *file_name)
{
  printf("[!]Usage: %s password\n", file_name);
  return;
}

int main(int argc, char *argv[])
{
  char password[PASS_LEN];
  char user_pass[PASS_LEN];
  
  if (argc < 2)
  {
    print_usage(argv[0]);
    return -1;
  }
  
  pass_gen(password);

  int i;
  for(i = 0; i < strlen(argv[1]); i++)
  {
    if(argv[1][i] == '%' && argv[1][i+1] == 'n')
    {
      printf("[!]No format string attacks please.\n");
      return -1;
    }
  }

  snprintf(user_pass, PASS_LEN, argv[1]);

  if(strncmp(user_pass, password, PASS_LEN) == PASS_LEN)
  {
    execl(JACKPOT, JACKPOT, NULL);
  }
  else
  {
    printf("[!]Try again!\n");
  }
  return 0;
}
