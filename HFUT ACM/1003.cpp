#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#define K 12
#define N 15005

int G[K];
int W[K];
int d[K][N];

int max_of_2(int a, int b)
{
    if (a >= b) return a;
    return b;
}

int main()
{
    int n, k;
    while (~scanf("%d%d", &n, &k)) {
    for (int i = 1; i <= k; i++) {
        scanf("%d%d", G+i, W+i);
    }

    memset(d, 0, sizeof(d));
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            int up_lim = j / G[i];
            for (int kk = 1; kk <= up_lim; kk++) {
                d[i][j] = max_of_2(d[i][j] ,max_of_2( d[i-1][j], d[i-1][j-kk*G[i]] + kk*W[i]) );
            }
        }
    }
    printf("%d\n", d[k][n]);
    }

    return 0;
}
