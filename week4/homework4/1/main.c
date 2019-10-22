#include "uhead.h"

#define BUFFERSIZE  8192

int main()
{
	int n ;
	char buf[BUFFERSIZE];
	while((n = read(STDIN_FILENO, buf, BUFFERSIZE)) > 0)
	{
		if(write(STDOUT_FILENO, buf, n) != 0)
			perror("write error");
	}
	if (n < 0)
		perror("read error");
	exit(0);
}
