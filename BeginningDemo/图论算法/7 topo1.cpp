/// °´ÕÕ×ÖµäĞòÊä³öÍØÆËĞòÁĞ

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define N 1005

int n, e;
vector<int> G[N];
int ind[N];
bool visited[N];
vector<int> out;

void topo()
{
    out.clear();
    memset(visited, 0, sizeof(visited));

    while (out.size() != n) {
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && ind[i] == 0) {
                out.push_back(i);
                u = i;
                visited[i] = true;

                for (int j = 0; j < G[i].size(); j++) {
                    int v = G[i][j];
                    ind[v]--;
                }
                break;
            }
        }

        if (-1 == u) { break; }
    }

    for (int i = 0; i < out.size(); i++) {
        if (i) { cout << " "; }
        cout << out[i];
    }
    cout << endl;
}


int main()
{
    scanf("%d %d", &n, &e);
    memset(ind, 0, sizeof(ind));

    for (int i = 0; i < e; i++) {
        int u, v;
        scanf(" %d %d", &u, &v);
        G[u].push_back(v);
        ind[v]++;
    }

    topo();

    return 0;
}
