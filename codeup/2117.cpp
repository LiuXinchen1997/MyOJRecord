/// WA :-(

#include <iostream>
#include <vector>

using namespace std;

#define N 505

vector<int> adj[N];
int ind[N];
bool visited[N];
int n, m;

bool init()
{
    cin >> n >> m;
    if (n == 0 && m == 0) { return false; }
    for (int i = 1; i <= n; i++) {
        ind[i] = 0;
        visited[i] = false;
    }

    for (int i = 1; i <= m; i++) {
        int c1, c2;
        cin >> c1 >> c2;
        adj[c1].push_back(c2);
        ind[c2]++;
    }

    return true;
}

int searchPoint()
{
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0 && !visited[i]) {
            return i;
        }
    }
}

int main()
{
    while (1) {
        if (!init()) { break; }

        vector<int> out;
        while (out.size() != n) {
            int u = searchPoint();
            out.push_back(u);
            visited[u] = true;

            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i];
                ind[v]--;
            }
        }

        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << out[i];
        }
        cout << endl;
    }


    return 0;
}
