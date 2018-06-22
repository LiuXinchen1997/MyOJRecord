#include <iostream>
#include <fstream>

using namespace std;

#define N 100
#define INF (1<<29)
#define WHITE 0
#define GRAY 1
#define BLACK 2

int G[N][N];
int n;
int color[N];
int d[N];
int f[N];

void dijkstra(int s)
{
    // init
    for (int i = 0; i < n; i++) {
        color[i] = WHITE;
        d[i] = INF;
        f[i] = -1;
    }

    d[s] = 0;
    while (true) {
        int u = -1;
        int minu = INF;

        for (int i = 0; i < n; i++) {
            if (color[i] == WHITE && d[i] < minu) {
                minu = d[i];
                u = i;
            }
        }

        if (u == -1) { break; }
        color[u] = BLACK;

        for (int v = 0; v < n; v++) {
            if (color[v] == WHITE) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    f[v] = u;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << i << " " << d[i] << endl;
    }
}

int main()
{
    ifstream infile("data2.txt");
    infile >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            G[i][j] = INF;
        }
    }

    for (int i = 0; i < n; i++) {
        int u, k;
        infile >> u >> k;
        for (int j = 0; j < k; j++) {
            int v, vl;
            infile >> v >> vl;
            G[u][v] = vl;
        }
    }

    dijkstra(0);


    return 0;
}
