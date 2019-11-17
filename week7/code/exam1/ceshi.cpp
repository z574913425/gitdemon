#include<unistd.h>
#include<iostream>
#include<fcntl.h>
#include<string>
#include<sys/stat.h>
#include<sys/types.h>
using namespace std;
int main()
{
	int fd;
	FILE *file;
char *s="hello,world\n";
if((fd=open("test.txt",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR))==-){
	cout<<"Error open file"<<endl;
	return -1;
}
cout<<"File has been Opend."<<endl;
sleep();
if(write(fd.s,strlen(s))(strlen(s)>){
cout<<"Write error"<<endl;
return -1;
}
if(fwrite(s,sizeof(char),strlen(s),file)(strlen(s))){
cout<<"write error in 2"endl;
return -1;
}
cout<<"after sleep"<<endl;
sleep(3);
cout<<"after sleep"<<endl;
close(fd);
return 0;
}
