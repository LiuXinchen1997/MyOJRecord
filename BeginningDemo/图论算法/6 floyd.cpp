#include <cstdio>
#include <iostream>

using namespace std;

#define N 1005
#define INF (1<<30)
int graph[N][N];
int n, e;

void floyd()
{
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (graph[i][k] == INF) { continue; }
            for (int j = 1; j <= n; j++) {
                if (graph[k][j] == INF) { continue; }
                if (graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

int main()
{
    scanf("%d %d", &n, &e);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = (i == j ? 0 : INF);
        }
    }

    for (int i = 1; i <= e; i++) {
        int u, v, w;
        scanf(" %d %d %d", &u, &v, &w);
        graph[u][v] = w;
    }

    floyd();

    bool flag = false;
    for (int i = 1; i <= n; i++) {
        if (graph[i][i] < 0) { flag = true; break; }
    }

    if (flag) { cout << "NEG!" << endl; }
    else {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (j-1) { cout << " "; }
                if (graph[i][j] == INF) {
                    cout << "INF";
                } else {
                    cout << graph[i][j];
                }
            }
            cout << endl;
        }
    }

    return 0;
}
