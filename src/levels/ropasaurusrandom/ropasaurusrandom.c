#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

#define edie(reason)  do{             \
                      perror(reason); \
                      exit(-1);       \
                      }while(0);

void gadgets()
{
gadget_0:
  asm(
    "movb $0x3b, %al\n"
    "int $0x80\n"
    "ret"
  );

gadget_1:
  asm(
    "xorl %eax, %eax\n"
    "ret"
  );

gadget_2:
  asm(
    "pushl %eax\n"
    "pushl %ebx\n"
    "pushl %edx\n"
    "pushl %edi\n"
    "movl %esp, %ebx\n"
    "xor %eax, %eax\n"
    "pushl %eax\n"
    "pushl %esp\n"
    "pushl %ebx\n"
    "pushl %eax\n"
    "movb $0x3b, %al\n"
    "int $0x80\n"
    "ret"
  );

gadget_3:
  asm(
    "movl $0x70755f6c, %ebx\n"
    "movl $0x65766f6c, %edx\n"
    "movl $0x2f2f2f2f, %edi\n"
    "ret"
  );

gadget_4:
  asm(
    "pushl %eax\n"
    "ret"
  );
}
int main(int argc, char *argv[])
{
  char address[64];
  int fd;
  printf("[+]Executing binary %s, main loaded at %p\n", argv[0], main);
  usleep(500);

  if((fd = open(argv[1], O_RDONLY | O_NOFOLLOW)) < 0)
  {
    edie("open");
  }



  if ((read(fd, address, 128)) < 0)
  {
    edie("read");
  }

  return (int)address;
}
