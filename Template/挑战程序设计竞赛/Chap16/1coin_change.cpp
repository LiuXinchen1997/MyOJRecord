#include <stdio.h>

#define M 22
#define MAX 50005
#define INF (1<<20)
int coin[M];
int dp[MAX];

int min_of_2 (int a, int b)
{
    if (a < b) return a;
    return b;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= m; i++) {
        scanf("%d", &coin[i]);
    }

    for (int i = 0; i <= n; i++) {
        dp[i] = INF;
    }
    dp[0] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = coin[i]; j <= n; j++) {
            dp[j] = min_of_2(dp[j], dp[j-coin[i]] + 1);
        }
    }

    printf("%d\n", dp[n]);

    return 0;
}
