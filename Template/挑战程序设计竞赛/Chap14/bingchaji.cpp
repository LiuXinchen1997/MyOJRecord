#include <iostream>

using namespace std;

#define N 100

int rankk[N];
int p[N];
int n;

void make_set()
{
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        rankk[i] = 0;
    }
}

void union_set(int a, int b)
{
    if (rankk[a] > rankk[b]) {
        p[b] = a;
    } else {
        p[a] = b;
        if (rankk[a] == rankk[b]) {
            rankk[b]++;
        }
    }
}

int find_parent(int a)
{
    if (p[a] != a) {
        p[a] = find_parent(p[a]);
        return p[a];
    }
    return a;
}

bool same(int a, int b)
{
    if (find_parent(a) == find_parent(b)) { return true; }
    return false;
}

int main()
{
    cin >> n;
    make_set();

    return 0;
}
