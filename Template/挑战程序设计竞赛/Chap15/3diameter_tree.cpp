#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

#define N 100
#define INF (1<<29)

class Edge
{
public:
    int v, c;
    Edge(int vv, int cc) : v(vv), c(cc) {}
    Edge() {}
};

int d[N];
vector<Edge> G[N];
int n;

void bfs(int s)
{
    for (int i = 0; i < n; i++) {
        d[i] = INF;
    }

    queue<int> q;
    d[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < G[u].size(); i++) {
            Edge e = G[u][i];
            if (d[e.v] == INF) {
                d[e.v] = d[u] + e.c;
                q.push(e.v);
            }
        }
    }
}

int main()
{
    ifstream infile("data3.txt");
    infile >> n;

    for (int i = 1; i < n; i++) {
        int u, v, c;
        infile >> u >> v >> c;
        G[u].push_back(Edge(v, c));
        G[v].push_back(Edge(u, c));
    }

    bfs(0);
    int u = -1, maxu = -INF;
    for (int i = 0; i < n; i++) {
        if (d[i] > maxu) {
            maxu = d[i];
            u = i;
        }
    }

    bfs(u);
    maxu = -INF;
    for (int i = 0; i < n; i++) {
        if (d[i] > maxu) {
            maxu = d[i];
        }
    }
    cout << maxu << endl;

    return 0;
}
