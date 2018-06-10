#include <stdio.h>
#include <cstring>
using namespace std;

int w[3405];
int d[3405];
int dp[12885];

int max_of_2(int a, int b)
{
    if (a > b) {
        return a;
    }
    return b;
}

int main()
{
    memset(dp, 0, sizeof(dp));
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &w[i], &d[i]);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = m; j - w[i] >= 0; j--) {
            dp[j] = max_of_2(dp[j], dp[j-w[i]] + d[i]);
        }
    }
    printf("%d\n", dp[m]);

    return 0;
}
