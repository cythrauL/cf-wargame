#include <stdio.h>
#include <unistd.h>
#include <string.h>

/*Function that allows us to escape the main loop*/
int escape_loop()
{
  int selection = 0;
  while(selection != 1 && selection != 2)
  {
    printf("\n\n1: Escape Loop\n2: Change Coordinate\n");
    scanf("%u", &selection);
  }
  return selection-1;
}

int coord_loop()
{
  /*Define Matrix*/
  unsigned char coordinates[12][12];
  /*Get sizeof Matrix*/
  unsigned int size = sizeof(coordinates);
  
  /*Multi dimensional arrays are guranteed to be sequencial in memory
   *so we can memset the sizeof the matrix from the first address to
   *zero the matrix*/
  memset(coordinates, '\x00', size);

  /*Placeholder variables*/
  unsigned int new_x = 0, new_y = 0;
  unsigned char new_val = 0;

  /*Main Loop*/
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
  
  /*Escape Loop?*/
  if(!escape_loop())
  {
    break;
  }

  /*Assign New Val*/
  printf("\n\nChange coordinates :\n");
  printf("\nNew X Y and value: ");
  scanf("%u %u %c", &new_x, &new_y, &new_val); 
  coordinates[new_x][new_y] = new_val;
  /*Assign New Val END*/ 
  }
  return 0;
}

int main(int argc, char *argv[])
{
  /*Enter main loop*/
  coord_loop();
  return 0;
}
