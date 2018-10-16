#include <iostream>
#include <fstream>

using namespace std;

#define MAXN 505
#define INF (1<<30)
int n, m;
int graph[MAXN][MAXN] = {INF};
int res[MAXN] = {0};
int d[MAXN] = {INF};
bool visited[MAXN] = {false};

int num[MAXN] = {0};
int w[MAXN] = {0};

void init()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = INF;
        }
        res[i] = 0;
        d[i] = INF;
        visited[i] = false;
        num[i] = 0;
        w[i] = 0;
    }
}

int main()
{
    // ifstream infile("A1003data.txt");
    // infile >> n >> m;
    cin >> n >> m;
    init();

    int start, dest;
    // infile >> start >> dest;
    cin >> start >> dest;

    for (int i = 0; i < n; i++) {
        // infile >> res[i];
        cin >> res[i];
    }

    for (int i = 0; i < m; i++) {
        int c1, c2, len;
        // infile >> c1 >> c2 >> len;
        cin >> c1 >> c2 >> len;
        if (graph[c1][c2] == INF) {
            graph[c1][c2] = len; graph[c2][c1] = len;
        } else {
            if (graph[c1][c2] > len) {
                graph[c1][c2] = len; graph[c2][c1] = len;
            }
        }
    }

    /// Dijkstra
    d[start] = 0;
    w[start] = res[start];
    num[start] = 1;

    while (true) {
        int u = -1, minlen = INF;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && d[i] < minlen) {
                u = i;
                minlen = d[i];
            }
        }

        if (u == -1) { break; }
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != INF && !visited[v]) {
                if (graph[u][v] + d[u] < d[v]) {
                    num[v] = num[u];
                    w[v] = w[u] + res[v];
                    d[v] = graph[u][v] + d[u];
                } else if (graph[u][v] + d[u] == d[v]) {
                    num[v] += num[u];
                    if (w[v] < w[u] + res[v]) {
                        w[v] = w[u] + res[v];
                    }
                }
            }
        }
    }

    cout << num[dest] << " " << w[dest] << endl;

    return 0;
}
