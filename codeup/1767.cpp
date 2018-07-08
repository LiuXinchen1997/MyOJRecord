#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

#define N 55

vector<int> adj[N];
bool visited[N];
int ind[N];
int n;

void init()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        ind[i] = 0;
        visited[i] = false;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int t; cin >> t;
            if (t) {
                adj[i].push_back(j);
                ind[j]++;
            }
        }
    }
}

void toposort()
{
    init();

    stack<int> st;
    vector<int> out;

    for (int i = 0; i < n; i++) {
        if (0 == ind[i]) {
            st.push(i);
        }
    }

    while (!st.empty()) {
        int u = st.top(); st.pop();
        out.push_back(u);
        visited[u] = true;

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            ind[v]--;
            if (0 == ind[v]) {
                st.push(v);
            }
        }
    }

    if (out.size() != n) {
        cout << "ERROR" << endl;
    } else {
        for (int i = 0; i < out.size(); i++) {
            cout << out[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    toposort();
    return 0;
}
