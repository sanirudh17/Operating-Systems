#include <stdio.h>

int main() {
    int p, r, i, j, k;
    int alloc[20][20], max[20][20], need[20][20];
    int avail[20], finish[20] = {0}, safe[20];
    int count = 0, flag;

    printf("Enter number of processes");
    scanf("%d", &p);

    printf("Enter number of resource types");
    scanf("%d", &r);

    printf("Enter Allocation Matrix");
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Max Matrix");
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available Resources");
    for (i = 0; i < r; i++)
        scanf("%d", &avail[i]);

    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    while (count < p) {
        flag = 0;
        for (i = 0; i < p; i++) {
            if (finish[i] == 0) {
                int possible = 1;
                for (j = 0; j < r; j++) {
                    if (need[i][j] > avail[j]) {
                        possible = 0;
                        break;
                    }
                }
                if (possible) {
                    for (k = 0; k < r; k++)
                        avail[k] += alloc[i][k];
                    safe[count] = i;
                    finish[i] = 1;
                    flag = 1;
                    count++;
                }
            }
        }
        if (flag == 0)
            break;
    }

    if (count < p) {
        printf("System is NOT in a safe state\nDeadlock may occur.");
    } else {
        printf("System is in a SAFE STATE.\nSafe Sequence ");
        for (i = 0; i < p; i++)
            printf("P%d ", safe[i]);
    }

    return 0;
}
