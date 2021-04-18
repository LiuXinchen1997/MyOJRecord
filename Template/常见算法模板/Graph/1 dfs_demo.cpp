#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

#define N 1005
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, m;
int graph[N][N];
int color[N];
int d[N], f[N], tt;

void dfs_visit(int u)
{
    color[u] = GRAY;
    d[u] = ++tt;
    cout << u << " ";
    for (int v = 1; v <= n; v++) {
        if (graph[u][v] && color[v] == WHITE) {
            dfs_visit(v);
        }
    }

    color[u] = BLACK;
    f[u] = ++tt;
}

void dfs()
{
    tt = 0;
    for (int i = 1; i <= n; i++) { color[i] = WHITE; }

    for (int i = 1; i <= n; i++) {
        if (color[i] == WHITE) { dfs_visit(i); }
    }
    cout << endl;
}

int main()
{
    scanf("%d %d", &n, &m);
    memset(graph, 0, sizeof(graph));
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf(" %d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    dfs();

    return 0;
}
