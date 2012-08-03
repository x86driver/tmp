#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: %s [count]\n", argv[0]);
        exit(1);
    }

    int count = atoi(argv[1]);
    int *array = malloc(sizeof(int)*count);
    int i;

    srand(time(0));

    for (i = 0; i < count; ++i) {
        array[i] = rand() % 100;
    }

    int sum = 0;
    for (i = 0; i < count; ++i) {
        sum += array[i];
    }

    printf("ave1: %f\n", (double)sum/count);

    double ave = 0;
    for (i = 0; i < count; ++i) {
        ave *= i;
        ave += array[i];
        ave /= i + 1;
    }

    printf("ave2: %f\n", ave);

    return 0;
}
