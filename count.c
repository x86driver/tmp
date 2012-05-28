#include <stdio.h>

int main()
{
    int numbers[] = {1, 3, 3, 4, 4, 4, 4, 4};
    int total = sizeof(numbers) / sizeof(numbers[0]);
    int sum = 0;

    int i, j;

    i = 0;
    while (i < total) {
        int comp = numbers[i];
        for (; i < total; ++i) {
            int curr = numbers[i];
            if (comp == curr) {
                sum += numbers[i];
            } else {
                break;
            }
        }
        printf("number: %d, total: %d\n", comp, sum);
        sum = 0;
    }

#if 0
    for (i = 0; i < total;) {
        int comp = numbers[i];
        for (j = i; j < total; ++i, ++j) {
            int curr = numbers[j];
            if (comp == curr) {
                sum += numbers[j];
            } else {
                i = j;
                break;
            }
        }
        printf("number: %d, total: %d\n", comp, sum);
        sum = 0;
    }
#endif

    return 0;
}
