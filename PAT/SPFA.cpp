#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAXN 1010
#define INF (1<<30)

struct Node {
    int v, dist;
};

vector<Node> adj[MAXN];
bool inq[MAXN];
int d[MAXN];
int nums[MAXN];
int n, m;

void init()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        inq[i] = false;
        d[i] = INF;
        nums[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int c1, c2, dist;
        cin >> c1 >> c2 >> dist;
        Node node; node.v = c2; node.dist = dist;
        adj[c1].push_back(node);
    }
}

bool spfa(int s)
{
    init();
    queue<int> q;
    d[s] = 0;
    q.push(s);
    nums[s]++;
    inq[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop(); inq[u] = false;

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].v;
            int dist = adj[u][i].dist;
            if (d[u] + dist < d[v]) {
                d[v] = d[u] + dist;
                if (!inq[v]) {
                    q.push(v);
                    inq[v] = true;
                    nums[v]++;
                    if (n <= nums[v]) { return false; }
                }
            }
        }
    }

    return true;
}

int main()
{
    spfa(0);

    return 0;
}
