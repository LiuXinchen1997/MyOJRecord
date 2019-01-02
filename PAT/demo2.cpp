#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define N 10005
#define WHITE 0
#define GRAY 1
#define BLACK 2

vector<int> G[N];

int visited[N],d[N];
int n;

void bfs(int s)
{
    for (int i = 1; i <= n; i++) {
        d[i] = -1;
        visited[i] = WHITE;
    }

    queue<int> q;
    q.push(s);
    d[s] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            if (visited[v] == WHITE) { 
                q.push(v);
                d[v] = d[u] + 1; 
                visited[v] = GRAY;
            }
        }
        visited[u] = BLACK;
    }
}
