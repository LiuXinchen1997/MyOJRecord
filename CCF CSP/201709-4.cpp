#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define N 1002

vector<int> edges[N];
bool graph[N][N];
bool visited[N];

void dfs(int a, int b)
{
    visited[a] = true;
    graph[a][b] = true;
    graph[b][a] = true;
    for (int i = 0; i < edges[a].size(); i++) {
        if (!visited[edges[a][i]]) {
            dfs(edges[a][i], b);
        }
    }
}

int main()
{
    memset(graph, false, sizeof(graph));
    memset(visited, false, sizeof(visited));
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));
        dfs(i,i);
    }

    int num = 0;
    int j;
    for (int i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (!graph[i][j]) {
                break;
            }
        }
        if (j == n+1) {
            num++;
        }
    }
    cout << num << endl;

    return 0;
}
