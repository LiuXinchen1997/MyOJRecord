#include <iostream>
#include <algorithm>

using namespace std;

#define N 55
#define INF (1<<30)

int graph[N][N];
int n;

void init()
{
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int dist; cin >> dist;
            graph[i][j] = (dist == 0 ? INF : dist);
        }
        graph[i][i] = 0;
    }
}

void floyd()
{
    init();
    for (int k = 0; k < n; k++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (graph[u][k] != INF && graph[k][v] != INF && graph[u][k] + graph[k][v] < graph[u][v]) {
                    graph[u][v] = graph[u][k] + graph[k][v];
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
            cout << (graph[i][j] >= INF ? -1 : graph[i][j]) << " ";
        }
        cout << endl;
    }

    return 0;
}
