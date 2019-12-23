#include"my.h"

int main()
{
	int pid;
	if(pid=fork()<0)
	{
		perror("failes to fork!\n");
		return -1;
	}
	else if(pid==0)

	{
		printf("%d:child is exit now\n",getpid());
		printf("%d:parent is running\n",getpid());
		exit(120);
	}
	else
	{
		printf("%d:parent is waiting zombie now\n",getpid());
	wait(NULL);
	printf("%d:parent is exiting now\n",getpid());	
	}
	exit(0);
}
