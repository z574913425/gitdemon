#include"my.h"
static void __attribute__((constructor)) before_main()
{
	printf("running before main!\n");
}

static void callback1()
{
	printf("1:running after main!\n");
}
static void callback2()
{
	printf("2:running after main!\n");
}
static void callback3()
{
	printf("3:running after main!\n");
}
int main()
{
	atexit(callback1);
	atexit(callback2);
	atexit(callback3);
	printf("test1:pid=%d,ppid=%d\n",getpid(),getppid());
	for(int i=0;i<argc;i++)
		printf("test3:argc[%d]:%s\n",i,argv[]);
	sleep(2);
	printf("test3 finish running!");
	return 0;
}
