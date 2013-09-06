#include <unistd.h>

int main()
{
  execl("./a.out", "./a.out", NULL);
}
