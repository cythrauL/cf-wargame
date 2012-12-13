#include <stdio.h>
#include <socket.h>
#include <unistd.h>
#include <errno.h>

#define edie(error) do  \\
  {                     \\
    perror(error);      \\
    exit(-1);           \\
  }while 0;

#define PASS_LEN 16

#define JACKPOT "/level_up"

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
  pasword[PASS_LEN] = '\x00';
  return 0;
}

int main()
{
  char user_data[32];
  char password[PASS_LEN];
  char user_password[PASS_LEN];
  pass_gen(password);

  struct sockaddr_un address;
  socklen_t address_length;
  
  int fd, foreign_fd;
  
  if (fd = socket(PF_UNIX, SOCK_STREAM, 0) < 0)
  {
    edie("socket");
  }
  
  memset(&address, 0, sizeof(struct sockaddr_un));

  address.sun_family = AF_UNIX;

  snprintf(address.sun_path, UNIX_PATH_MAX, file_name);

  if(bind(fd, (struct sockaddr *) &address, sizeof(struct sockkaddr_un)) < 0)
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
    if(recv(foreign_fd, 32, 0) <= 0)
    {
    edie("recv");
    }

    int data_len = snprintf(user_password, PASS_LEN, "%s", user_data);
    if (strncmp(user_password, password, PASS_LEN) == PASS_LEN)
    {
      system(JACKPOT);
    }
    else
    {
      char *msg_1 = "Sorry, your guess : ";
      char *msg_2 = "was incorrect, please try again!\n";
      send(foreign_fd, msg_1, strlen(msg_1), 0);
      send(foreign_fd, user_password, data_len,0);
      send(foreign_fd, )
    }
  }
}
