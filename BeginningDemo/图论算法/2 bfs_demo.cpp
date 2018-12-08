#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

#define N 1005
#define WHITE 0
#define GRAY 1
#define BLACK 2

int graph[N][N];
int color[N], d[N];
int n;

void bfs(int s)
{
    for (int i = 1; i <= n; i++) {
        color[i] = WHITE;
        d[i] = -1;
    }

    d[s] = 1;
    color[s] = GRAY;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && color[v] == WHITE) {
                color[v] = GRAY;
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
        color[u] = BLACK;
    }
}

int main()
{
    scanf("%d", &n);

    // init
    memset(graph, 0, sizeof(graph));
    for (int i = 1; i <= n; i++) {
        int u, k;
        scanf(" %d %d", &u, &k);
        for (int j = 1; j <= k; j++) {
            int v;
            scanf(" %d", &v);
            graph[u][v] = 1;
            graph[v][u] = 1;
        }
    }

    // bfs: source point is 1
    bfs(1);

    return 0;
}
