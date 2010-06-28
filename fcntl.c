#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char buf[512];
	int fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		perror("open");
		exit(10:
	}

	read(fd, buf, 17);
	fcntl(fd, F_GETFL, 


	close(fd);
	return 0;
}
