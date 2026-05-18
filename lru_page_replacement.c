#include <stdio.h>

int main() {
    int n, framesCount, i, j;
    int pages[100], frames[100], time[100];
    int faults = 0, hits = 0, counter = 0;

    printf("Enter number of pages in reference string");
    scanf("%d", &n);

    printf("Enter the reference string");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames");
    scanf("%d", &framesCount);

    for (i = 0; i < framesCount; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    for (i = 0; i < n; i++) {
        int found = 0;
        for (j = 0; j < framesCount; j++) {
            if (frames[j] == pages[i]) {
                hits++;
                counter++;
                time[j] = counter;
                found = 1;
                break;
            }
        }
        if (!found) {
            int lruIndex = 0;
            for (j = 1; j < framesCount; j++) {
                if (time[j] < time[lruIndex])
                    lruIndex = j;
            }
            frames[lruIndex] = pages[i];
            counter++;
            time[lruIndex] = counter;
            faults++;
        }
    }

    printf("Total Page Faults %d", faults);
    printf("Total Page Hits %d", hits);

    return 0;
}
