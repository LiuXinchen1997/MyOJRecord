#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define N 100

int n, e;
vector<int> G[N];
int color[N];
bool visited[N];

void dfs(int u, int id)
{
    color[u] = id;
    visited[u] = true;
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (visited[v]) { continue; }
        dfs(v, id);
    }
}

int main()
{
    ifstream infile("data2.txt");
    infile >> n >> e;

    // Build the graph.
    for (int i = 1; i <= e; i++) {
        int u, v;
        infile >> u >> v;
        G[u].push_back(v);
    }
    for (int i = 0; i < n; i++) {
        color[i] = -1;
        visited[i] = false;
    }

    int id = 1;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, id++);
        }
    }

    int k;
    infile >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        infile >> a >> b;
        if (color[a] == color[b]) { cout << "yes" << endl; }
        else { cout << "no" << endl; }
    }

    return 0;
}
