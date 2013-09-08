#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

/*This is the same problem as lonetuna in PlaidCTF 2013 :)*/

/*Our struct*/
typedef struct animal
{
  char name[16];
  char sound[16];
} animal;

void goal_function()
{
  printf("Congratulations!\n");
  return;
}


/*Opens a file and reads 4 bytes into an int,
 *(the number of structs to read), and then
 *reads that much data into a buffer, 
 *dies on error*/
unsigned int read_struct(animal *buff)
{
  unsigned int struct_no = 0;
  int fd;

  /*open file*/
  if ((fd = open("/tmp/structs", O_RDONLY)) == -1)
  {
    perror("open");
    exit(-1);
  }
  /*read data*/
  if (read(fd, &struct_no, 4) != 4)
  {
    perror("read");
    exit(-1);
  }
  /*use data read as unsigned int that denotes how many structs to expect*/
  if (read(fd, buff, sizeof(animal) * struct_no) < sizeof(animal) * struct_no)
  {
    perror("read");
    exit(-1);
  }

  return struct_no;
}

/*A mock function*/
int make_noise()
{
  animal buff[32];
  unsigned int counter;

  counter = read_struct(buff);

  unsigned int i;
  for(i = 0; i < counter; i++)
  {
    printf("The %s goes %s!\n", buff[i].name, buff[i].sound);
  }

  return 0;
}
/*main func*/

int main()
{
  make_noise();
  return 0;
}
