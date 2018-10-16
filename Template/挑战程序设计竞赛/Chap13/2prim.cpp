#include <iostream>
#include <fstream>
using namespace std;

#define INF (1<<29)
#define N 104
#define WHITE 0
#define GRAY 1
#define BLACK 2

int G[N][N];
int n;
int color[N];
int d[N];
int f[N];

void prim(int s)
{
    for (int i = 1; i <= n; i++) {
        d[i] = INF;
        f[i] = -1;
        color[i] = WHITE;
    }

    d[s] = 0;
    while (true) {
        int u = -1;
        int minu = INF;
        for (int i = 1; i <= n; i++) {
            if (color[i] == WHITE && d[i] < minu) {
                u = i;
                minu = d[i];
            }
        }

        if (u == -1) { break; }
        color[u] = BLACK;

        for (int i = 1; i <= n; i++) {
            if (color[i] == WHITE) {
                if (G[u][i] < d[i]) {
                    d[i] = G[u][i];
                    f[i] = u;
                }
            }
        }
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (f[i] != -1) {
            sum += G[f[i]][i];
        }
    }
    cout << sum << endl;
}

int main()
{
    ifstream infile("data.txt");
    infile >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int dist;
            infile >> dist;
            G[i][j] = (dist == -1 ? INF : dist);
        }
    }

    prim(1);
    return 0;
}
