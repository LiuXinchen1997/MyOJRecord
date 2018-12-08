#include <iostream>
#include <cstdio>

using namespace std;

#define N 1005

int f[N];
int rankk[N];

void make_set(int n)
{
    for (int i = 0; i < n; i++) {
        f[i] = i;
        rankk[i] = 1;
    }
}

/*
int find_f(int x)
{
    if (x != f[x]) {
        f[x] = find_f(f[x]);
    }

    return f[x];
}
*/

int find_f(int x)
{
    int a = x;
    while (x != f[x]) {
        x = f[x];
    }

    while (a != f[a]) {
        int z = a;
        a = f[a];
        f[z] = x;
    }

    return x;
}

void union_set(int x, int y)
{
    x = find_f(x);
    y = find_f(y);
    if (rankk[x] > rankk[y]) {
        f[y] = x;
    } else {
        f[x] = y;
        if (rankk[x] == rankk[y]) {
            rankk[y]++;
        }
    }
}

bool same(int x, int y) {
    return find_f(x) == find_f(y);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    make_set(n);

    for (int i = 1; i <= m; i++) {
        int type, x, y;
        scanf(" %d %d %d", &type, &x, &y);
        if (0 == type) {
            union_set(x, y);
        } else {
            if (same(x, y)) {
                printf("Yes!\n");
            } else {
                printf("No!\n");
            }
        }
    }

    return 0;
}