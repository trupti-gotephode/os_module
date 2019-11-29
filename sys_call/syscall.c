#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char const *argv[])
{


	int fd = open("syscall.txt", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (-1 == fd)
	{
		perror("UNABLE TO OPEN");
	}


	int wr = write(fd, "OS IMPLEMENTs SYSCALL IN KERNEL SPACE", 37);
	if (wr == -1)
	{
		perror("UNABLE TO WRITE");
	}


	int cl = close( fd);
	if (cl == -1)
	{
		perror("UNABLE TO WRITE");
	}





	return 0;
}