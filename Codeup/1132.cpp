#include <stdio.h>
#include <string.h>

#define N 105

char a[N], b[N];
int dp[N][N];

int main()
{
    while (~scanf("%s %s", &a, &b)) {
        int la = strlen(a);
        int lb = strlen(b);

        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= la; i++) {
            for (int j = 1; j <= lb; j++) {
                if (a[i-1] == b[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else { dp[i][j] = (dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1]); }
            }
        }

        printf("%d\n", dp[la][lb]);
    }

    return 0;
}
