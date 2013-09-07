#include <stdio.h>
#include <unistd.h>

gadget_1:
  asm{
    "pushl %eip"
    "popl %esp"
    "ret"
  }

gadget_2:
  asm{
  
  }

int main(int argc, char *argv[])
{
  char address[64];
  printf("[+]Executing binary %s, main loaded at %p\n", argv[0], main);
  usleep(500);

  int fd = open(argv[1], O_RDONLY | O_NOFOLLOW);

  read(fd, address, 128);

  return (int)address;
}
