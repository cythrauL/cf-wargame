#include <stdio.h>
#include <unistd.h>
void jackpot(char *sys)
{
	system(sys);
}

int print_name(char *buff)
{
	printf("Welcome to the wargame, %s!\n", buff);
	return 0;
}


int get_name()
{
	char buff[48];
	if(buff != gets(buff))
	{
		return -1;
	}
	return print_name(buff);
}


int main(int arc, char *argv[])
{
	return get_name();
}
