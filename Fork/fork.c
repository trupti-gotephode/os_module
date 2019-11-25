 #include <sys/types.h>
       #include <unistd.h>
#include<stdio.h>
int main(int argc, char const *argv[])
{
	printf("BEFORE FORK\n");
	fork();
	fork();
	fork();  
	printf("AFTER FORK %d\n",getpid());
	
	return 0;
}

       

