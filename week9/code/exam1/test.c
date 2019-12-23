#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	pid_t result;
	result=fork();
	int newret;
	if(result==-1)
{
	perror("chuanjianshibai");
		exit;
}
else if(result=0)
{
	print("");
	newret=system("ls -1");
}
	else{
	sleep(10);
	printf("");
	newret=system("ping www.lupaworld.com");
}
}
