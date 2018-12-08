#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

#define N 10005
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n;
vector<int> G[N];
int color[N], d[N], f[N], tt;

void dfs_visit(int u)
{
    color[u] = GRAY;
    d[u] = ++tt;
    int v;
    for (int i = 0; i < G[u].size(); i++) {
        if (color[G[u][i]] == WHITE) { dfs_visit(G[u][i]); }
    }
    color[u] = BLACK;
    f[u] = ++tt;
}

void dfs()
{
    // init
    tt = 0;
    for (int i = 1; i <= n; i++) {
        color[i] = WHITE;
    }

    for (int i = 1; i <= n; i++) {
        if (color[i] == WHITE) { dfs_visit(i); }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d %d %d\n", i, d[i], f[i]);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int u, k;
        scanf(" %d %d", &u, &k);
        for (int j = 1; j <= k; j++) {
            int v; scanf(" %d", &v);
            G[u].push_back(v);
        }
    }

    dfs();

    return 0;
}
