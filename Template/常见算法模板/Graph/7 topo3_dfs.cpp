// 深搜输出拓扑序列
// 未完成

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

#define N 1005

vector<int> G[N];
int ind[N], visited[N];
int n, e;
vector<int> out;

void dfs(int s)
{
}

int main()
{
    memset(ind, 0, sizeof(ind));
    memset(visited, 0, sizeof(visited));

    scanf("%d %d", &n, &e);
    for (int i = 1; i <= e; i++) {
        int u, v;
        scanf(" %d %d", &u, &v);
        G[u].push_back(v);
        ind[v]++;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && ind[i] == 0) {
            dfs(i);
        }
    }

    reutrn 0;
}