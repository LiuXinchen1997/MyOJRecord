#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, tt;
int M[N][N];
int color[N];

void dfs_visit(int u)
{
    color[u] = GRAY;
    cout << u << " ";
    for (int v = 0; v < n; v++) {
        if (M[u][v] == 0) { continue; }
        if (color[v] == WHITE) {
            dfs_visit(v);
        }
    }

    color[u] = BLACK;
}

void dfs()
{
    for (int i = 0; i < n; i++) { color[i] = WHITE; }
    tt = 0;

    for (int u = 0; u < n; u++) {
        if (color[u] == WHITE) { dfs_visit(u); }
    }
}

int main()
{
    int u, v, k;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            M[i][j] = 0;
        }
    }

    // ³õÊ¼»¯
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &u, &k);
        u--;
        for (int j = 0; j < k; j++) {
            scanf("%d", &v);
            v--;
            M[u][v] = 1;
        }
    }

    dfs();

    return 0;
}
