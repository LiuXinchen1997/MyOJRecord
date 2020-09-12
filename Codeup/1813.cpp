#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

#define MAXN 105
#define INF (1<<30)
int graph[MAXN][MAXN];
int d[MAXN];
bool visited[MAXN];
int p[MAXN];
int n, m;
// ifstream infile("1813data.txt");

void init()
{
    m = n * (n-1) / 2;
    for (int i = 0; i < m; i++) {
        int u, v, dist;
        cin >> u >> v >> dist;
        // infile >> u >> v >> dist;
        graph[u][v] = dist;
        graph[v][u] = dist;
    }

    for (int i = 1; i <= n; i++) {
        visited[i] = false;
        d[i] = INF;
        p[i] = -1;
    }
}

int prim(int s)
{
    init();
    d[s] = 0;

    while (1) {
        int u = -1, mind = INF;
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && d[i] < mind) {
                u = i;
                mind = d[i];
            }
        }

        if (u == -1) { break; }
        visited[u] = true;

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] < d[v]) {
                d[v] = graph[u][v];
                p[v] = u;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (p[i] != -1) {
            ans += graph[p[i]][i];
        }
    }

    cout << ans << endl;
}

int main()
{
    while (cin >> n, n) {
        prim(1);
    }

    return 0;
}
