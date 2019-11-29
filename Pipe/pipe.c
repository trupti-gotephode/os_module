#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 
#define BUFF_SIZE 1024

int main()
{
	pid_t id;
	int pfd1[2];
	int pfd2[2];
	
	char input[100];
	
	
	scanf("%s", input);
	pipe(pfd1);
	pipe(pfd2);
	
	id = fork();
	if (id == 0)
	{
		unsigned char buffer[BUFF_SIZE];

		close(pfd1[1]);
		read(pfd1[0], buffer, BUFF_SIZE);
		printf("fd1 buff %s",buffer);
		close(pfd2[0]);
		write(pfd2[1], buffer, BUFF_SIZE);
		close(pfd2[1]);
	}
	else
	{	
		unsigned char i[BUFF_SIZE];
		close(pfd1[0]);
		write(pfd1[1], input, BUFF_SIZE);
		close(pfd2[1]);

		wait(NULL);

		read(pfd2[0], i, BUFF_SIZE);
		printf("fd2 buff %s\n", i);
		close(pfd2[0]);
	}

}