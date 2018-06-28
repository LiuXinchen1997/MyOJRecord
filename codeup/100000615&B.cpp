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
    int n, m;
    while (~scanf("%d", &n)) {
        if (0 == n) { break; }
        scanf(" %d", &m);

        make_set(n);
        for (int i = 1; i <= m; i++) {
            int a, b;
            scanf(" %d %d", &a, &b);
            int f_a = find_f(a);
            int f_b = find_f(b);

            if (f_a != f_b) { union_set(a, b); }
        }

        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (f[i] == i) { cnt++; }
        }

        printf("%d\n", cnt-1);
    }

    return 0;
}
