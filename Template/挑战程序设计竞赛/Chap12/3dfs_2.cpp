#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n;
int M[N][N];
int color[N];

void dfs_visit(int u)
{
    color[u] = BLACK;
    cout << u << " ";
    for (int v = 0; v < n; v++) {
        if (!M[u][v]) { continue; }
        if (color[v] == BLACK) { continue; }
        dfs_visit(v);
    }
}

void dfs()
{
    for (int i = 0; i < n; i++) {
        color[i] = WHITE;
    }

    for (int i = 0; i < n; i++) {
        if (color[i] == WHITE) {
            dfs_visit(i);
        }
    }
}

int main()
{
    ifstream infile("data.txt");
    infile >> n;

    // ½¨Í¼
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            M[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        int u, k;
        infile >> u >> k;
        u--;

        for (int j = 0; j < k; j++) {
            int v;
            infile >> v;
            v--;
            M[u][v] = 1;
        }
    }

    dfs();

    return 0;
}
