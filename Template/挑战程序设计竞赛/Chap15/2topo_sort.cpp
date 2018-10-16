#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

using namespace std;

#define N 100
int ind[N];
int visited[N];
vector<int> G[N];

int main()
{
    ifstream infile("data2.txt");
    memset(ind, 0, sizeof(ind));
    memset(visited, 0, sizeof(visited));
    int n, e;
    infile >> n >> e;

    for (int i = 1; i <= e; i++) {
        int u, v;
        infile >> u >> v;
        G[u].push_back(v);
        ind[v]++;
    }

    while (true) {
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (ind[i] == 0 && visited[i] == 0) {
                u = i;
                cout << u << endl;
                visited[i] = 1;
                break;
            }
        }

        if (u == -1) { break; }
        for (int i = 0; i < G[u].size(); i++) {
            ind[G[u][i]]--;
        }
    }

    return 0;
}
