#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main()
{
	char cmd[100];
	int id;
	while (1)
	{
		printf("Enter command\n");
		scanf("%s", cmd);
		id = fork();
		if (0 == id) {
			execl((const char*)cmd, (const char*)cmd, ...);
		}
	}
	return 0;
}