#include<stdio.h>
#include<stdlib.h>

int main()
{
	if(pid=fork()<0)
	{
		perror("failes to fork!\n");
		return -1;
	}
	else if(pid==0)

	{
		printf("child is exit now\n",getpid());
		exit(0);
	}
	else
	{
		printf("%d:parent is running\n",getpid());
	while(1)	
	}
	exit(0);
}
