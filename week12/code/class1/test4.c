#include "my.h"

int count=0;
int main(){
	pid_t p1,p2,p3;
	int fd1[65536],fd2[65536];
	pipe(fd1);
	pipe(fd2);
	p1 = fork();
	if(p1<0){
		perror("fork failed\n");
		return -1;
	}else if(p1==0){
		for(int i=0;i<65535;i++){
			fd1[i] = i;
		}
	}
}
