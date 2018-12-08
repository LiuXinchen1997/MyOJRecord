#include <cstdio>
#include <iostream>

using namespace std;

#define N 1005
#define INF (1<<30)
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n;
int graph[N][N];
int color[N], d[N], f[N];

void dijkstr(int s)
{
    // init
    for (int i = 0; i < n; i++) {
        color[i] = WHITE;
        d[i] = INF;
        f[i] = -1;
    }

    d[s] = 0;
    color[s] = GRAY;
    while (1) {
        int u = -1;
        int minu = INF;
        for (int i = 0; i < n; i++) {
            if (color[i] != BLACK && d[i] < minu) {
                u = i;
                minu = d[i];
            }
        }

        if (-1 == u) { break; }
        color[u] = BLACK;
        for (int v = 0; v < n; v++) {
            if (color[v] != BLACK && graph[u][v] != INF) {
                if (d[u] + graph[u][v] < d[v]) {
                    d[v] = d[u] + graph[u][v];
                    f[v] = u;
                    color[v] = GRAY;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d %d\n", i, d[i]);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            graph[i][j] = INF;
        }
    }

    for (int i = 0; i < n; i++) {
        int u, k;
        scanf(" %d %d", &u, &k);

        for (int j = 1; j <= k; j++) {
            int v, w;
            scanf(" %d %d", &v, &w);
            graph[u][v] = w;
            graph[v][u] = w;
        }
    }

    dijkstr(0);

    return 0;
}
