#include <stdio.h>

int main() {
    int m, n, i, j;

    printf("Enter number of memory blocks");
    scanf("%d", &m);

    int block[m], remain[m];

    printf("Enter size of each block");
    for (i = 0; i < m; i++) {
        scanf("%d", &block[i]);
        remain[i] = block[i];
    }

    printf("Enter number of processes");
    scanf("%d", &n);

    int process[n];

    printf("Enter size of each process");
    for (i = 0; i < n; i++)
        scanf("%d", &process[i]);

    for (i = 0; i < n; i++) {
        int allocated = 0;
        for (j = 0; j < m; j++) {
            if (remain[j] >= process[i]) {
                int fragment = remain[j] - process[i];
                printf("Process %d of size %d is allocated to Block %d of size %d with Fragment %d",
                       i + 1, process[i], j + 1, block[j], fragment);
                remain[j] -= process[i];
                allocated = 1;
                break;
            }
        }
        if (!allocated)
            printf("Process %d of size %d is not allocated", i + 1, process[i]);
    }

    return 0;
}
