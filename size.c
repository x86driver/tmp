#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <linux/fs.h>

int main(int argc, char **argv)
{
	if (argc != 2) {
		printf("Usage: %s [device]\n", argv[0]);
		exit(1);
	}

	unsigned long blocks = 0;
	int ret;
	int fd = open(argv[1], O_RDWR);
	if (fd == -1) {
		perror("open");
		exit(1);
	}

	ret = ioctl(fd, BLKGETSIZE, &blocks);
	if (ret == -1) {
		perror("ioctl");
	}

	printf("block size: %d\n", blocks);

	close(fd);
	return 0;
}
