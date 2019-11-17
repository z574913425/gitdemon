#include"my.h"
#include<setjmp.h>
static jmp_buf g_stack_env;
static void fun1(void);
static void fun2(void);
int mian(void)
{
	if(0==setjmp(g_stack_env)){
	printf("Normal flow\n");
	fun1();
}else{
	printf("Long jump flow");
}
	return 0;
}
static void fun1()

{
	printf("Enter func1\n");
	fun2();	
}
static void fun2()
{
	printf("Enter func2\n");
	longjmp(g_stack_env);
	printf("Leave func2\n");
}
