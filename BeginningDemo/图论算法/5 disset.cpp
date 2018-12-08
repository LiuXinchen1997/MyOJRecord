#include <iostream>
#include <cstdio>

using namespace std;

#define N 1005

int f[N];
int rankk[N];
int n, m;

void make_set(int n)
{
    for (int i = 0; i < n; i++) {
        f[i] = i;
        rankk[i] = 1;
    }
}

int find_f(int i)
{
    if (i != f[i]) {
        f[i] = find_f(f[i]);
    }

    return f[i];
}

void union_set(int x, int y)
{
    x = find_f(x);
    y = find_f(y);
    if (rankk[x] < rankk[y]) {
        f[x] = y;
    } else {
        f[y] = x;
        if (rankk[x] == rankk[y]) {
            rankk[x]++;
        }
    }
}

bool same(int x, int y)
{
    return find_f(x) == find_f(y);
}

int main()
{
    scanf("%d %d", &n, &m);

    // init
    make_set(n);

    for (int i = 1; i <= m; i++) {
        int type, x, y;
        scanf(" %d %d %d", &type, &x, &y);
        if (0 == type) {
            union_set(x, y);
        } else {
            if (same(x, y)) {
                printf("%d\n", 1);
            } else {
                printf("%d\n", 0);
            }
        }
    }

    return 0;
}
