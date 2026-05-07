#include <stdio.h>

#define MOD 1000000007

int main() {
    int N;
    scanf("%d", &N);

    if (N == 0) {
        printf("1");
        return 0;
    }
    if (N == 1) {
        printf("1");
        return 0;
    }
    if (N == 2) {
        printf("2");
        return 0;
    }

    long long dp[N + 1];

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= N; i++) {
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % MOD;
    }

    printf("%lld", dp[N]);

    return 0;
}
