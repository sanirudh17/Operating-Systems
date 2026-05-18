#include <stdio.h>

int main() {
    int m, n, i, j;

    printf("Enter number of memory blocks");
    scanf("%d", &m);

    int blockSize[m], original[m];

    printf("Enter size of each block");
    for (i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
        original[i] = blockSize[i];
    }

    printf("Enter number of processes");
    scanf("%d", &n);

    int processSize[n];

    printf("Enter size of each process");
    for (i = 0; i < n; i++)
        scanf("%d", &processSize[i]);

    for (i = 0; i < n; i++) {
        int bestIndex = -1;
        for (j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIndex == -1 || blockSize[j] < blockSize[bestIndex])
                    bestIndex = j;
            }
        }
        if (bestIndex != -1) {
            int fragment = blockSize[bestIndex] - processSize[i];
            printf("Process %d of size %d is allocated to Block %d of size %d with Fragment %d",
                   i + 1, processSize[i], bestIndex + 1, original[bestIndex], fragment);
            blockSize[bestIndex] -= processSize[i];
        } else {
            printf("Process %d of size %d is not allocated", i + 1, processSize[i]);
        }
    }

    return 0;
}
