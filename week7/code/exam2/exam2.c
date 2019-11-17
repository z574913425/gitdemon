#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

char buf[]={"write to stdout\n"};
int main()
{
	pid_t id;
	if(write(STDOUT_FILENO,buf,sizeof(buf)-1)!=sizeof(buf)-1)
		perror("cant write");
	printf("printf\n");
	id=fork();
	if(id<0)
			perror("fork error");
	exit(0);
}
