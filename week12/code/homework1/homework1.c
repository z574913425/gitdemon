#include "my.h"

int main()
{
	pid_t p1, p2, p3;
	int fd1[2], fd2[2];
	char w_buf[50],r_buf[50];
	memset(w_buf,0,50);
	memset(r_buf,0,50);
	int i;
	int r1,r2,r3,s1,s2,s3;
	long int sum=0,x;
	pipe(fd1);
	pipe(fd2);
	
	p1 = fork();	
	if(p1 < 0)
	{
		perror("fork1 failed.\n");
		return -1;
	}
	else if(p1 == 0)
	{
		close(fd1[0]);
		printf("child1: pid=%d ppid=%d\n", getpid(), getppid());
		for (i=0;i<65536;i++){
			sprintf(w_buf,"%d",i);
			write(fd1[1], w_buf, sizeof(w_buf));
		}
		close(fd1[1]);
		printf("child1: write 0-65535 to pipe1\n");
		exit(99);
	}
	else
	{
		p2 = fork();
		if(p2 < 0)
		{
			perror("fork2 failed.\n");
			return -1;
		}
		else if(p2 == 0)
		{
			close(fd1[1]);
			close(fd2[0]);
			printf("child2: pid=%d ppid=%d\n", getpid(), getppid());
			for(i=0;i<65536;i++){
				read(fd1[0],r_buf,sizeof(r_buf));
				sscanf(r_buf,"%ld",&x);
				sprintf(w_buf,"%ld",x);
				write(fd2[1],w_buf,sizeof(w_buf));
			}
			printf("child1: read pipe1 0-65535\n");
			printf("child2: write pipe2 0-65535\n");
			close(fd1[0]);
			close(fd2[1]);
			exit(34);
		}
		else
		{
			p3 = fork();
			if(p3 < 0)
			{
				perror("fork3 failed.\n");
				return -1;
			}
			else if(p3 == 0)
			{
				close(fd2[1]);
				printf("child3: pid=%d ppid=%d\n", getpid(), getppid());
				for(i=0;i<65536;i++){
					read(fd2[0],r_buf,sizeof(r_buf));
					sscanf(r_buf,"%ld",&x);
					printf("%ld ",x);
					sum+=x;
					
				}
				printf("\nchild3: read pipe2 0-65535\n");
				printf("sum=%ld",sum);
				close(fd2[0]);
				exit(67);
			}
			else
			{
				r1=wait(&s1);
				r2=wait(&s2);
				r3=wait(&s3);			
				printf("r1=%d,s1=%d,r2=%d,s2=%d,r3=%d,s3=%d\n",r1,WEXITSTATUS(s1),r2,WEXITSTATUS(s2),r3,WEXITSTATUS(s3));
				printf("parent pid=%d\n",getpid());
			}
		}
		printf("parent: end\n");
		return 0;
	}
}
