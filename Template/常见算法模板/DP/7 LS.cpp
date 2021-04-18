#include <iostream>
#include <cstdio>

using namespace std;

#define N 1405
int G[N][N], dp[N][N];

int max_of_2(int x, int y)
{
    return (x > y ? x : y);
}

int min_of_2(int x, int y)
{
    return (x < y ? x : y);
}

int main()
{
    int h, w;
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf(" %d", &G[i][j]);
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (1 == G[i][j]) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = 1;
            }
        }
    }

    int maxWidth = 0;
    for (int i = 1; i < h; i++) {
        for (int j = 1; j < w; j++) {
            if (G[i][j] == 0) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = min_of_2(dp[i-1][j], min_of_2(dp[i][j-1], dp[i-1][j-1])) + 1;
                maxWidth = max_of_2(maxWidth, dp[i][j]);
            }
        }
    }

    cout << maxWidth * maxWidth << endl;

    return 0;
}