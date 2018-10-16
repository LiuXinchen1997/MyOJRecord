#include <stdio.h>

#define N 1005

int f[N];
int rankk[N];

void make_set(int n)
{
    for (int i = 1; i <= n; i++) {
        f[i] = i;
        rankk[i] = 1;
    }
}

int find_f(int i)
{
    if (f[i] != i) {
        f[i] = find_f(f[i]);
    }

    return f[i];
}

void union_set(int a, int b)
{
    a = find_f(a);
    b = find_f(b);
    if (a == b) { return; }
    if (rankk[a] > rankk[b]) {
        f[b] = a;
    } else {
        f[a] = b;
        if (rankk[a] == rankk[b]) {
            rankk[b]++;
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf(" %d %d", &n, &m);
        make_set(n);

        for (int i = 1; i <= m; i++) {
            int a, b;
            scanf(" %d %d", &a, &b);
            union_set(a, b);
        }

        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (i == f[i]) { cnt++; }
        }
        printf("%d\n", cnt);
    }

    return 0;
}
