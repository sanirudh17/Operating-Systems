#include <stdio.h>

int main() {
    int n, tq, i, time = 0, completed = 0;
    int at[50], bt[50], rt[50], ct[50], tat[50], wt[50];
    float avgtat = 0, avgwt = 0;

    printf("Enter number of processes");
    scanf("%d", &n);

    printf("Enter Time Quantum");
    scanf("%d", &tq);

    for (i = 0; i < n; i++) {
        printf("Enter AT and BT for P%d ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    while (completed != n) {
        int done = 1;
        for (i = 0; i < n; i++) {
            if (rt[i] > 0 && at[i] <= time) {
                done = 0;
                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    ct[i] = time;
                    rt[i] = 0;
                    completed++;
                }
            }
        }
        if (done == 1)
            time++;
    }

    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avgtat += tat[i];
        avgwt += wt[i];
    }

    avgtat /= n;
    avgwt /= n;

    printf("Average Turnaround Time %.2f", avgtat);
    printf("Average Waiting Time %.2f", avgwt);

    return 0;
}
