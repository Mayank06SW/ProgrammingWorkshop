#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);

    int arrival[n], departure[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arrival[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &departure[i]);

    qsort(arrival, n, sizeof(int), compare);
    qsort(departure, n, sizeof(int), compare);

    int i = 0, j = 0;
    int platforms = 0, maxPlatforms = 0;

    while (i < n && j < n) {
        if (arrival[i] <= departure[j]) {
            platforms++;
            i++;
        } else {
            platforms--;
            j++;
        }
        maxPlatforms = max(maxPlatforms, platforms);
    }

    printf("%d", maxPlatforms);

    return 0;
}
