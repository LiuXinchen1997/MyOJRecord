#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define N 1005
#define TOP 0
#define DIAGONAL 1

int dp[N][N], G[N][N];
int n, lim;
int w[N], val[N];

int max_of_2(int x, int y)
{
    return (x > y ? x : y);
}

int main()
{
    scanf("%d %d", &n, &lim);
    for (int i = 1; i <= n; i++) {
        scanf(" %d", &w[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf(" %d", &val[i]);
    }

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= lim; j++) {
        dp[0][j] = 0;
        G[0][j] = DIAGONAL;
    }
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++) {
        for (int j = w[i]; j <= lim; j++) {
            if (dp[i-1][j] > dp[i-1][j-w[i]] + val[i]) {
                dp[i][j] = dp[i-1][j];
                G[i][j] = TOP;
            } else {
                dp[i][j] = dp[i-1][j-w[i]] + val[i];
                G[i][j] = DIAGONAL;
            }
            // dp[i][j] = max_of_2(dp[i-1][j], dp[i-1][j-w[i]] + val[i]);
        }
    }
    cout << dp[n][lim] << endl;

    vector<int> selection;
    for (int i = n, j = lim; i > 0; i--) {
        if (G[i][j] == DIAGONAL) {
            selection.push_back(i);
            j = j - w[i];
        }
    }

    for (vector<int>::iterator it = selection.begin(); it != selection.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
