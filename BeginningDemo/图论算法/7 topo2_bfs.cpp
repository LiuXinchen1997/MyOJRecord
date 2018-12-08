/// 按照宽搜输出拓扑序列
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

#define N 1005

int n, e;
vector<int> G[N];
int ind[N], visited[N];
vector<int> out;

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        out.push_back(u);
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            ind[v]--;
            if (0 == ind[v] && !visited[v]) { q.push(v); visited[v] = true; }
        }
    }
}

int main()
{
    memset(ind, 0, sizeof(ind));
    memset(visited, 0, sizeof(visited));

    scanf("%d %d", &n, &e);
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf(" %d %d", &u, &v);
        G[u].push_back(v);
        ind[v]++;
    }

    for (int u = 0; u < n; u++) {
        if (0 == ind[u] && !visited[u]) {
            bfs(u);
        }
    }

    for (int i = 0; i < out.size(); i++) {
        cout << out[i] << " ";
    }
    cout << endl;

    return 0;
}