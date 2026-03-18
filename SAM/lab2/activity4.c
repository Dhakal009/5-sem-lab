/*
    Find the period of the generator for a = 13, m =64, and X0 = 1,2,3,4 using the multiplicative congruential method and shows the result as follows. Your prgram should print minimum and maximum cycle length detected for which value of seeds
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a, m;
    int seedCount;
    int i;

    int minCycleLength = -1;
    int maxCycleLength = -1;
    int minSeed = 0;
    int maxSeed = 0;

    printf("Enter multiplier a: ");
    scanf("%d", &a);
    printf("Enter modulus m: ");
    scanf("%d", &m);

    if (m <= 1) {
        printf("Modulus m must be greater than 1.\n");
        return 1;
    }

    printf("Enter how many different x0 values you want to test: ");
    scanf("%d", &seedCount);

    if (seedCount <= 0) {
        printf("Number of seeds must be positive.\n");
        return 1;
    }

    for (i = 0; i < seedCount; i++) {
        int x0Input;
        int x0;
        int x;
        int step;
        int cycleStart;
        int cycleLength;

        int *seen = (int *)malloc(sizeof(int) * m);
        int *sequence = (int *)malloc(sizeof(int) * (m + 1));

        if (seen == NULL || sequence == NULL) {
            printf("Memory allocation failed.\n");
            free(seen);
            free(sequence);
            return 1;
        }

        printf("\nEnter x0 for seed %d: ", i + 1);
        scanf("%d", &x0Input);

        x0 = x0Input % m;
        if (x0 < 0) {
            x0 += m;
        }

        for (step = 0; step < m; step++) {
            seen[step] = -1;
        }

        x = x0;
        seen[x] = 0;
        sequence[0] = x;
        step = 0;

        while (1) {
            int next = (a * x) % m;
            if (next < 0) {
                next += m;
            }

            step++;
            sequence[step] = next;

            if (seen[next] != -1) {
                cycleStart = seen[next];
                cycleLength = step - seen[next];
                break;
            }

            seen[next] = step;
            x = next;

            if (step == m) {
                cycleStart = 0;
                cycleLength = 0;
                break;
            }
        }

        printf("Generated numbers for x0 = %d: ", x0Input);
        for (int j = 0; j <= step; j++) {
            printf("%d ", sequence[j]);
        }
        printf("\nCycle starts after %d number(s)\n", cycleStart);
        printf("Cycle length for x0 = %d is %d\n", x0Input, cycleLength);

        if (minCycleLength == -1 || cycleLength < minCycleLength) {
            minCycleLength = cycleLength;
            minSeed = x0Input;
        }

        if (maxCycleLength == -1 || cycleLength > maxCycleLength) {
            maxCycleLength = cycleLength;
            maxSeed = x0Input;
        }

        free(seen);
        free(sequence);
    }

    printf("\nSummary:\n");
    printf("Minimum cycle length = %d for x0 = %d\n", minCycleLength, minSeed);
    printf("Maximum cycle length = %d for x0 = %d\n", maxCycleLength, maxSeed);

    return 0;
}