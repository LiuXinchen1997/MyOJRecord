#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define N 105
#define W 10005
#define TOP 0
#define DIAGONAL 1

struct Item {
    int w, v;
} items[N];
int dp[N][W];
int G[N][W];

int max_of_2(int x, int y)
{
    return (x > y ? x : y);
}

int main()
{
    int n, w;
    scanf("%d %d", &n, &w);
    for (int i = 1; i <= n; i++) { scanf(" %d %d", &items[i].v, &items[i].w); }
    for (int i = 1; i <= w; i++) {
        G[0][i] = DIAGONAL;
    }

    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = items[i].w; j <= w; j++) {
            int a = dp[i-1][j];
            int b = dp[i-1][j-items[i].w] + items[i].v;
            if (b > a) {
                G[i][j] = DIAGONAL;
                dp[i][j] = b;
            } else {
                G[i][j] = TOP;
                dp[i][j] = a;
            }
        }
    }

    cout << dp[n][w] << endl;

    vector<int> selection;
    for (int i = n, j = w; i >= 1; i--) {
        if (G[i][j] == DIAGONAL) {
            selection.push_back(i);
            j -= items[i].w;
        }
    }
    reverse(selection.begin(), selection.end());

    for (int i = 0; i < selection.size(); i++) {
        if (i) cout << " ";
        cout << selection[i];
    }
    cout << endl;

    return 0;
}
