#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

#define N 100
#define INF (1<<29)
int G[N][N];

int min_of_2(int a, int b)
{
    return (a < b ? a : b);
}

void floyd(int n)
{
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (G[i][k] == INF) { continue; }
            for (int j = 0; j < n; j++) {
                if (G[k][j] == INF) { continue; }
                G[i][j] = min_of_2(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
}

int main()
{
    ifstream infile("data.txt");
    int n, e;
    infile >> n >> e;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            G[i][j] = (i == j ? 0 : INF);
        }
    }

    for (int i = 1; i <= e; i++) {
        int u, v, c;
        infile >> u >> v >> c;
        G[u][v] = c;
    }

    floyd(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j) cout << " ";
            if (G[i][j] == INF) { cout << "INF"; }
            else { cout << G[i][j]; }
        }
        cout << endl;
    }

    return 0;
}
