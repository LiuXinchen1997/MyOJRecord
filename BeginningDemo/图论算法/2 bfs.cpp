#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define N 1005
#define WHITE 0
#define GRAY 1
#define BLACK 2
vector<int> G[N];

int color[N], d[N];
int n;

void bfs(int s)
{
    // init
    for (int i = 1; i <= n; i++) {
        color[i] = WHITE;
        d[i] = -1;
    }

    queue<int> q;
    q.push(s);
    d[s] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            if (color[v] == WHITE) {
                // visit!
                color[v] = GRAY;
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
        color[u] = BLACK;
    }

    for (int i = 1; i <= n; i++) {
        cout << i << " " << d[i] << endl;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int u, k;
        scanf(" %d %d", &u, &k);
        for (int j = 1; j <= k; j++) {
            int v;
            scanf(" %d", &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
    }

    bfs(1);

    return 0;
}
