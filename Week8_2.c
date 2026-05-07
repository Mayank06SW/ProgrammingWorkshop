#include <stdio.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);

    int height[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &height[i]);
    }

    int left_max[n], right_max[n];

    left_max[0] = height[0];
    for (int i = 1; i < n; i++) {
        left_max[i] = max(left_max[i-1], height[i]);
    }

    right_max[n-1] = height[n-1];
    for (int i = n-2; i >= 0; i--) {
        right_max[i] = max(right_max[i+1], height[i]);
    }

    int water = 0;

    for (int i = 0; i < n; i++) {
        water += min(left_max[i], right_max[i]) - height[i];
    }

    printf("%d", water);

    return 0;
}
