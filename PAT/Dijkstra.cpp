#include <iostream>
#include <vector>

using namespace std;

#define MAXN 1010
#define INF (1<<30)

int d[MAXN];
bool visited[MAXN];
vector<int> pre[MAXN];
int graph[MAXN][MAXN];
int n, m;

void init()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        d[i] = INF;
        visited[i] = false;
        for (int j = 0; j < n; j++) {
            graph[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int c1, c2, len;
        cin >> c1 >> c2 >> len;
        graph[c1][c2] = len;
        // graph[c2][c1] = len; // 如果是无向图的话
    }
}

void dijkstra(int s)
{
    init();
    d[s] = 0;

    while (1) {
        int u = -1, mind = INF;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && d[i] < mind) {
                mind = d[i];
                u = i;
            }
        }

        if (-1 == u) { break; }
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] < INF && !visited[v]) {
                if (d[u] + graph[u][v] < d[v]) {
                    d[v] = d[u] + graph[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (d[u] + graph[u][v] == d[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

int main()
{
    dijkstra(0);
    return 0;
}
