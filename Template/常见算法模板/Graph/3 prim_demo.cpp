#include <iostream>
#include <cstdio>

using namespace std;

#define N 1005
#define INF (1<<30)
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n;
int graph[N][N];
int color[N], d[N], f[N];

int prim(int s)
{
    for (int i = 1; i <= n; i++) {
        color[i] = WHITE;
        d[i] = INF;
        f[i] = -1;
    }

    color[s] = GRAY;
    d[s] = 0;
    while (1) {
        int u = -1;
        int minu = INF;
        for (int i = 1; i <= n; i++) {
            if (color[i] != BLACK && d[i] < minu) {
                u = i;
                minu = d[i];
            }
        }
        if (-1 == u) { break; }

        color[u] = BLACK;
        for (int v = 1; v <= n; v++) {
            if (color[v] != BLACK && graph[u][v] != -1) {
                if (graph[u][v] < d[v]) {
                    d[v] = graph[u][v];
                    f[v] = u;
                    color[v] = GRAY;
                }
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
