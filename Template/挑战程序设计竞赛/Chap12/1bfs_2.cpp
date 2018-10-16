#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n;
int M[N][N];
int color[N];

void bfs(int s)
{
    queue<int> q;
    color[s] = BLACK;
    q.push(s);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";

        for (int v = 0; v < n; v++) {
            if (!M[u][v]) { continue; }
            if (color[v] == BLACK) { continue; }
            color[v] = BLACK;
            q.push(v);
        }
    }
}

int main()
{
    // ½¨Í¼
    ifstream infile("data.txt");
    // scanf("%d", &n);
    infile >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            M[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        int u, k;
        // scanf("%d %d", &u, &k);
        infile >> u >> k;
        u--;
        for (int j = 0; j < k; j++) {
            int v;
            // scanf("%d", &v);
            infile >> v;
            v--;
            M[u][v] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        color[i] = WHITE;
    }

    bfs(0);

    return 0;
}
