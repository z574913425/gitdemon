#include<stdio>
#include<stdlib.h>
#define SIZE 512
int main(int argc,char *argv[])
{
	char buf[SIZE];
	if(setvbut(stdin,buf,_IONBF,SIZE)!=0)
{
	perror("hsurushibai!\n");
	return 1;
}
printf("chenggong!\n");
printf("stdin  wei");
if(stdin->_flags & _IO_UNBUFFERED)
{
	printf("wuhuanchong\n");
}
else if(stdin->_flags & _IO_LINE_BUF){
	printf("hanghuanchong\n");
}
else{
	printf("quanhuanchong\n");
}
printf("daxiaowei %d\n",stdin->_IO_buf_end - stdin->_IO_buf_base);
printf("miaoshufu %d\n",fileno(stdin));
if(setvbuf(stdin,buf,_IOFBF,SIZE)!=0)
{
	printf("xiugaishibai!\n");
return 2;
}
printf("xiugaichenggong!\n");
printf("stdin  wei");
if(stdin->_flags & _IO_UNBUFFERED){
	printf("wuhuanchong\n");
}else if(stdin->_flags & _IO_LINE_BUF)
{
	printf("hanghuanchong\n");
}
else{
	printf("quanhuanchong\n");
}
printf("daxiaowei %d\n",stdin->_IO_buf_end - stdin->_IO_buf_base);
printf("miaoshufu %d\n",fileno(stdin));
return 0;
}
