#include <string.h>
#include <stdio.h>

void goal_function()
{
  printf("Winner!\n");
  return;
}

int copy(char *string)
{
  char my_buff[16];
  strcpy(my_buff, string);
  return 0;
}

int main(int argc, char*argv[])
{
  if(argc < 2)
  {
    return -1;
  }
  return copy(argv[1]);
}
