#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

#define N 10005
int indeg[N];
int visited[N];
vector<int> graph[N];
vector<int> out;

int searchPoint(int n)
{
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0 && visited[i] == 0) { return i; }
    }
}

int main()
{
    int n, m;
    while (cin >> n >> m) {
        memset(visited, 0, sizeof(visited));
        memset(indeg, 0, sizeof(indeg));
        for (int i = 1; i <= m; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            indeg[b]++;
        }

        while (out.size() != n) {
            int cur = searchPoint(n);
            out.push_back(cur);
            visited[cur] = 1;
            for (int i = 0; i < graph[cur].size(); i++) {
                indeg[ graph[cur][i] ]--;
            }
        }

        for (int i = 0; i < out.size(); i++) {
            if (i) { cout << " "; }
            cout << out[i];
        }
        cout << endl;

        for (int i = 1; i <= n; i++) {
            graph[i].clear();
        }
        out.clear();
    }
    return 0;
}
