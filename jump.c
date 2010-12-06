#include <stdio.h>
#include <signal.h>
#include <setjmp.h>
#include <unistd.h>
#include <sys/types.h>

sigjmp_buf env;

void func(int signo)
{
        printf("Got a signal!, %d\n", signo);
        siglongjmp(env, 1);
}

int main()
{
        struct sigaction sig;
        sig.sa_handler = func;
        sigaction(SIGINT, &sig, NULL);
        printf("pid: %d\n", getpid());

        if (sigsetjmp(env, 1) != 0) {
                printf("jump from signal handler\n");
                while (1) {
                        pause();
                }
        } else {
                while (1) {
                        pause();
                }
        }

        return 0;
}

