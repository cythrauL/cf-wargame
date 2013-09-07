#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#define JACKPOT "/level_up"

#define edie(reason)  do{ perror(reason); \
                          exit(-1);       \
                          }while(0);

#define die(reason) do{ printf("%s", reason); \
                        exit(-1);             \
                        }while(0);


void makePass(char *pass)
{
  int randfd;
  
  if ( -1 == (randfd = open("/dev/urandom", O_RDONLY)))
    edie("how random...");

  if ( -1 == read(randfd, pass, 11))
    edie("read");

  /*terminate buffer*/
  pass[11] = '\x00';

  /*c99 compliant*/
  int place;

  /*manipulate pass*/
  for(place = 0; place < 11; place++)
  {
    if(pass[place] < 0)
      pass[place] = -pass[place];
  
    pass[place] = (unsigned char)(pass[place] % 25) + 65;
  }

  /*close fd*/
  if (-1 == close(randfd))
    edie("close");

  return;
}

int checkPass(char *pass)
{
  char *string = "[+]What's the password?\n";
  char yourPass[12];
  char unsuspiciousCheckBuffer[12];
  
  if (-1 == send(4, string, strlen(string), 0))
    edie("send");
  
  if (-1 == recv(4, yourPass, sizeof(yourPass), 0))
    edie("recv");

  snprintf(unsuspiciousCheckBuffer, 12, yourPass);
  
  return(memcmp(unsuspiciousCheckBuffer, pass, 12));
}

void quitter()
{
  printf("[!]The end :)\n");
  fflush(stdout);
  exit(-1);
}

void syspop()
{
  execl(JACKPOT, JACKPOT, NULL);
}

void reader()
{
  char *string = "[+]Any last words?\n";
  void (*fun) ();
  char buf[64];
  
  fun = quitter;

  if ( -1 == send(4, string, strlen(string), 0))
    edie("send");
  
  if ( -1 == recv(4, buf, 256, 0))
    edie("recv");

  buf[63] = '\x00';

  if ( -1 == send(4, buf, strlen(buf), 0))
    edie("send");

  fun();
}


int main(int argc, char *argv[])
{
  pid_t ppid, puid;
  FILE *fd;
  int num;
  char pass[12];
  void *pointer;
  char buf[80];
  
  pointer = syspop;
  errno = 0;

  if (argc < 2)
    die("[!]Usage: compound_problem name\n");

  if (1  == (ppid = getppid()))
    die("[!]You'l have to do better than that...\n");
  
  snprintf(buf, sizeof(buf),"/bin/ps -f -p %u | /usr/bin/grep %u", ppid, ppid);
  
  if ( NULL == ( fd = popen(buf, "r")))
    edie("popen");

  fscanf(fd, "%u", &puid);
  
  if(puid != 0)
    die("[!]Must be run by root process.\n");

  num = snprintf(buf, sizeof(buf), "Well you got this far, maybe you can get a little further, %s\n", argv[1]);

  if (-1 == send(4, buf, num, 0))
    edie("send");
  makePass(pass);

  if(checkPass(pass))
  {
    send(4, "[!]Guess again.", 15, 0);
    die("Guess again.");
  }
  reader();
  
  return 0;
}
