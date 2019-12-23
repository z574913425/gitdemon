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
	while((pid=wait(&s))!=1)
{	
	if(WIFEXITED(s))
{	
	printf("child is exiting normally.exit code=%d\n",pid,WEXITSTATUS(s));	
}
else if(WIFSIGNALED(s))
{
	printf("child %d exit by signal.signal no =%d\n",pid,WTERMSIG(s))	
}
else
{
	printf("not know!\n");
}
}
}
	exit(0);
}
