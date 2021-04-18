#include <cstdio>
#include <iostream>

using namespace std;

#define N 1005
#define INF (1<<30)
#define WHITE 0
#define GRAY 1
#define BLACK 2

int graph[N][N];
int n;

int prim(int s)
{
    // init
    int color[N], d[N], f[N];
    for (int i = 1; i <= n; i++) {
        color[i] = WHITE;
        d[i] = INF;
        f[i] = -1;
    }
    d[s] = 0;
    color[s] = GRAY;

    while (1) {
        int u = -1;
        int minu = INF;
        for (int v = 1; v <= n; v++) {
            if (color[v] != BLACK && d[v] < minu) {
                u = v;
                minu = d[v];
            }
        }
        if (u == -1) { break; }
        color[u] = BLACK;

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] != -1 && color[v] != BLACK && graph[u][v] < d[v]) {
                d[v] = graph[u][v];
                f[v] = u;
                color[v] = GRAY;
            }
        }
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (f[i] != -1) {
            sum += graph[f[i]][i];
        }
    }
    printf("%d\n", sum);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf(" %d", &graph[i][j]);
        }
    }

    prim(1);

    return 0;
}
