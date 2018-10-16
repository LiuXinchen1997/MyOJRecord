#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

#define N 10000

char x[N+1];
char y[N+1];

int dp[N+1][N+1];


int main()
{
    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", &x);
        scanf("%s", &y);
        int len1 = strlen(x);
        int len2 = strlen(y);

        for (int i = 0; i <= len1; i++) { dp[i][0] = 0; }
        for (int i = 0; i <= len2; i++) { dp[0][i] = 0; }

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (x[i] == y[j]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = dp[i][j-1] > dp[i-1][j] ? dp[i][j-1] : dp[i-1][j];
                }
            }
        }

        cout << dp[len1][len2] << endl;
    }

    return 0;
}
