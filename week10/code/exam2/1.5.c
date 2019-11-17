#include"my.h"
int g=10;
int main()
{
	int s=20;
	static int k=30;
	pid_t pid;
	pid=fork();
	if(pid<0)
	{
		perror("fork falled!\n");
	return -1;
	}
	else if(pid==0)
{
	printf("child:&g=%16p\n&k=%16p&s=%16p\n",getpid(),&g,&k,&s);
	g=100;
	k=100;
	s=100;
	printf("chile after g=%d,s=%d,k=%d\n",g,s,k);
	_exit(0);
}
else
{
	printf("child:&g=%16p\n&k=%16p&s=%16p\n",getpid(),&g,&k,&s);
	printf("chile after g=%d,s=%d,k=%d\n",g,s,k);
	return 0;
}
}
