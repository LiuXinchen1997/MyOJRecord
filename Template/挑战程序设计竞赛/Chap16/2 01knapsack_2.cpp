/// 动态规划采用的是 一维数组！！！

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

int dp[W];

int main()
{
    int n, w;
    scanf("%d %d", &n, &w);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    for (int i = 0; i <= w; i++) {
        dp[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = w; j >= 1; j--) {
            if (j < items[i].weight) { continue; }
            dp[j] = max_of_2(dp[j], dp[j-items[i].weight] + items[i].value);
        }
    }

    printf("%d\n", dp[w]);
}
