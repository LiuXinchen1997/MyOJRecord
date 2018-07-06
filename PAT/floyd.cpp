#include <iostream>

using namespace std;

#define MAXN 1010
#define INF (1<<30)

int dis[MAXN][MAXN];
int n, m;

void init()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dis[i][j] = INF;
        }
        dis[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v, dist;
        cin >> u >> v >> dist;
        dis[u][v] = dist;
    }
}

void floyd()
{
    init();
    for (int k = 0; k < n; k++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (dis[u][k] != INF && dis[k][v] != INF && dis[u][k] + dis[k][v] < dis[u][v]) {
                    dis[u][v] = dis[u][k] + dis[k][v];
                }
            }
        }
    }
}

int main()
{
    floyd();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dis[i][j] == INF) { cout << "INF "; }
            else { cout << dis[i][j] << " "; }
        }
        cout << endl;
    }

    return 0;
}
