#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
	char buff[100];
	const int size = 100;
	int fd = open("syscall.txt", O_RDONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (-1 == fd)
	{
		perror("UNABLE TO OPEN SYSCALL.TXT");
	}


	int rd = read(fd, buff, size);
	if (rd == -1)
	{
		perror("UNABLE TO READ");
	}


	int cl = close( fd);
	if (cl == -1)
	{
		perror("UNABLE TO CLOSE sys");
	}
	int fd1 = open("copy.txt", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (-1 == fd1)
	{
		perror("UNABLE TO OPEN COPY.TXT");
	}
	int wr = write(fd1, buff, size);

	int cl1 = close( fd);
	if (cl1 == -1)
	{
		perror("UNABLE TO CLOSE copy");

	}

	return 0;
}