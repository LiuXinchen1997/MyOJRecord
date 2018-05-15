#include <iostream>

using namespace std;

#define N 105
int val[N];

bool flag = true;
struct Node {
    int data;
    int lchild, rchild;
};

Node nodes[N];

void dfs(int lc, int rc)
{
    if (lc == 0 && rc == 0) {
        return;
    }

    if (lc==0&&rc!=0 || lc!=0&&rc==0 || nodes[lc].data!=nodes[rc].data) {
        flag = false;
        return;
    }

    dfs(nodes[lc].lchild, nodes[rc].rchild);

    if (!flag) { return; }

    dfs(nodes[lc].rchild, nodes[rc].lchild);
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        flag = true;
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            int f, lc, rc;
            cin >> f >> lc >> rc;
            nodes[f].lchild = lc;
            nodes[f].rchild = rc;
        }

        for (int i = 1; i <= n; i++) {
            cin >> nodes[i].data;
        }

        dfs(nodes[1].lchild, nodes[1].rchild);
        if (flag) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
