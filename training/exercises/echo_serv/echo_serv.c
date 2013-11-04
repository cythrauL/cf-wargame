#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#define PORT 31337
#define KEY_PATH "/tmp/key.txt"

#define edie(e)	do{		\
		perror(e);	\
		exit(errno);	\
		}while(0);

#define DEBUG 0

struct client_controll
{
	char local_buf[32];
	void (*exit_func) (int);
	char final_buf[64];
};

void questionable_debug_function(int sockfd)
{
	int fd;
	char buff[16];

	fd = open(KEY_PATH, 0);
	read(fd, buff, 16);
	send(fd, buff, 16, 0);
	close(fd);
	close(sockfd);
	exit(-1);
}

void std_exit(int sockfd)
{
	char *str = "[!] Goodbye!\n";
	send(sockfd, str, strlen(str), 0);
	close(sockfd);
	exit(0);
}
/*echo name back to client*/
void get_name(int sockfd)
{
	char out_buf[36];
	char name_buf[36];
	int data_len;

	recv(sockfd, name_buf, sizeof(name_buf), 0);
	data_len = snprintf(out_buf, sizeof(out_buf),"[+] Your name is: %s\n", name_buf);
	send(sockfd, out_buf, data_len, 0);

	return;
}
void handle_client(int sockfd)
{
	/*where the magic happens, handle all IO*/
	struct client_controll session;
	int data_len;
	get_name(sockfd);

	recv(sockfd, session.local_buf, 64, 0);
	data_len = snprintf(	session.final_buf, sizeof(session.final_buf),
				"[+] Your message is: %s\n", session.local_buf);
	if (data_len > sizeof(session.final_buf))
	{
		/*Bug-fix, weird bug where extra data was sent...*/
		data_len = sizeof(session.final_buf);
	}
	send(sockfd, session.final_buf, data_len, 0);

	if (DEBUG)
	{
		session.exit_func = questionable_debug_function;
	}

	session.exit_func(sockfd);
}

void accept_connection(int sock)
{
        struct sockaddr_in client_addr;
        int clientfd, pid, addrlen = sizeof(client_addr);
        /*Loop forever*/
        while(1)
        {
                if((clientfd = accept(sock, (struct sockaddr *)&client_addr, &addrlen)) < 0)
                {
                        edie("accept");
                }

                if((pid = fork()) < 0)
                {
                        edie("fork");
                }

                if(pid == 0)
                {
                        /*child process, handle client*/
                        close(sock);
			handle_client(clientfd);
			return;
                }

                else
                {
                        /*parent process, return to loop*/
                        close(clientfd);
                }


        }
	/*parent never returns*/
}


int main(int argc, char *argv[])
{
        /*Socket set up*/
	int sockopt = 1;
        int sock;
        struct sockaddr_in sockaddr_me;

        memset(&sockaddr_me, 0, sizeof(sockaddr_me));

        sockaddr_me.sin_family = AF_INET;
        sockaddr_me.sin_port = htons(PORT);
        sockaddr_me.sin_addr.s_addr = INADDR_ANY;

        if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        {
                edie("socket");
        }

	if(setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &sockopt, sizeof(sockopt)) < 0)
	{
		edie("setsockopt");
	}

        if(bind(sock, (struct sockaddr *) &sockaddr_me, sizeof(sockaddr_me)) != 0)
        {
                edie("bind");
        }

        if(listen(sock, 20) != 0)
        {
                edie("listen");
        }

	accept_connection(sock);
}

