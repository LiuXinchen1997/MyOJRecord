#include <iostream>
#include <stdio.h>

using namespace std;

#define N 1005
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
    int n, m;
    while(cin >> n >> m) {
        make_set(n);
        for (int i = 1; i <= m; i++) {
            char ch;
            int a, b;
            cin >> ch >> a >> b;
            if ('U' == ch) {
                union_set(a, b);
            } else {
                a = get_parent(a);
                b = get_parent(b);
                if (a == b) {
                    cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                }
            }
        }
    }
    return 0;
}
