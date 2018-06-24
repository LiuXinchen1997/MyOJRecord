#include <stdio.h>

#define N 105
#define W 10005

int max_of_2(int a, int b)
{
    if (a > b) return a;
    return b;
}

struct Item {
    int value, weight;
} items[N];

int dp[N][W];

int main()
{
    int n, w;
    scanf("%d %d", &n, &w);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }

    for (int i = 0; i <= w; i++) {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            if (j < items[i].weight) { continue; }
            dp[i][j] = max_of_2(dp[i-1][j], dp[i-1][j-items[i].weight] + items[i].value);
        }
    }

    printf("%d\n", dp[n][w]);
}
