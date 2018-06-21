#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INF (1<<30)

int n;
int M[N][N];
int color[N];
int d[N];

void bfs(int s)
{
    for (int i = 0; i < n; i++) {
        d[i] = INF;
    }

    queue<int> q;
    q.push(s);
    d[s] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for (int v = 0; v < n; v++) {
            if (M[u][v] == 0) { continue; }
            if (d[v] != INF) { continue; } // 还没有被访问
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            M[i][j] = 0;
        }
    }

    int u, k;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &u, &k);
        u--;

        for (int j = 0; j < k; j++) {
            int v;
            scanf("%d", &v);
            v--;
            M[u][v] = 1;
        }
    }

    bfs(0);

    return 0;
}
