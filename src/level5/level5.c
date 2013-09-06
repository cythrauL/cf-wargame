#include <fcntl.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/un.h>

#define edie(reason)  do{ perror(reason);      \
                          exit(-1);            \
                        }while(0);

#define UNIX_PATH_MAX 108
#define PASS_LEN 16
#define OUT_LEN 64
#define JACKPOT "/level_up"

#define OUT_FRAG_1 "[!]Password: "
#define OUT_FRAG_2 " was incorrect :(\n"

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
  password[PASS_LEN] = '\x00';
  return 0;
}

void print_usage(char *file_name)
{
  printf("Usage: %s sock_name\n", file_name);
  return;
}

int main(int argc, char *argv[])
{
  char sad_message[OUT_LEN];
  char password[PASS_LEN];
  char user_password[PASS_LEN];
  pass_gen(password);

  struct sockaddr_un address;
  socklen_t address_length;
  
  int fd, foreign_fd;

  if(argc < 2)
  {
    print_usage(argv[0]);
    return -1;
  }

  if (fd = socket(PF_UNIX, SOCK_STREAM, 0) < 0)
  {
    edie("socket");
  }
  
  memset(&address, 0, sizeof(struct sockaddr_un));

  address.sun_family = AF_UNIX;

  snprintf(address.sun_path, UNIX_PATH_MAX, "%s", argv[1]);

  if(bind(fd, (struct sockaddr *) &address, sizeof(struct sockaddr_un)) < 0)
  {
    edie("bind");
  }

  if(listen(fd, 5) != 0)
  {
    edie("listen");
  }

  if ((foreign_fd = accept(fd, (struct sockaddr *) &address, &address_length)) < 0)
  {
    edie("accept");
  }
  int c;
  for(c = 0; c < 20; c++)
  {
    if(recv(foreign_fd, user_password, PASS_LEN, 0) <= 0)
    {
    edie("recv");
    }

    if (strncmp(user_password, password, PASS_LEN) == PASS_LEN)
    {
      system(JACKPOT);
    }
    else
    {
      int data_len = snprintf(sad_message, OUT_LEN, "%s%s%s", OUT_FRAG_1, user_password, OUT_FRAG_2);
      send(foreign_fd, sad_message, data_len, 0);
    }
  }
}
