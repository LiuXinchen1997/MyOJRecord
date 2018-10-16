#include <iostream>
#include <cstring>
#include <set>
using namespace std;

#define N 100004

int parent[N];
int rankk[N];

void make_set(int n)
{
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rankk[i] = 0;
    }
}

int get_parent(int i)
{
    if (parent[i] == i) {
        return parent[i];
    } else {
        return get_parent(parent[i]);
    }
}

void union_set(int a, int b)
{
    a = get_parent(a);
    b = get_parent(b);
    if (a == b) { return; }
    if (rankk[a] > rankk[b]) { parent[b] = a; }
    else {
        if (rankk[a] == rankk[b]) { rankk[b]++; }
        parent[a] = b;
    }
}


int main()
{
    int n;
    while (cin >> n) {
        make_set(n);

        for (int i = 1; i <= n; i++) {
            int n1, n2;
            cin >> n1 >> n2;
            union_set(n1, n2);
        }

        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (parent[i] == i) {
                res++;
            }
        }

        cout << res << endl;
    }

    return 0;
}
