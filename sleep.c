#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void func(int no)
{
	printf("in signal handler\n");
}

int main()
{
	struct sigaction sig;
	sig.sa_handler = func;
	int r = sigaction(SIGUSR1, &sig, NULL);
	if (r == -1)
		perror("sigaction");
	printf("pid: %d\n", getpid());
	unsigned int ret = sleep(5);
	printf("ret: %d\n", ret);
	return 0;
}
