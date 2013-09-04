#include <stdio.h>
#include <unistd.h>
#include <string.h>

int coord_loop()
{
  unsigned char coordinates[12][12];
  unsigned int size = sizeof(coordinates);
  memset(coordinates, '\x00', size);

  unsigned int new_x = 0, new_y = 0;
  unsigned char new_val;

  for(;;)
  {
    printf("\n\n");
    /*Print Loop*/
    int x, y;
    for(x = 0, y = 0; x * (y + 1) <  size; x++)
    {
      if(x == 12)
      {
       x = 0;
       y++;
       printf("\n");
      }
      printf("%2u ", coordinates[x][y]);
    }
    /*Print Loop END*/
  
  /*assign new val*/
  printf("\n\nChange coordinates :\n");
  printf("\nNew X Y and value: ");
  scanf("%u %u %c", &new_x, &new_y, &new_val); 
  /*assign new val END*/
  coordinates[new_x][new_y] = new_val;
  }
}

int main(int argc, char *argv[])
{
  coord_loop();
  return 1;
}
