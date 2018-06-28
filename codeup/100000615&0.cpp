/// WA :-(

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
    while (~scanf("%d %d", &n, &m)) {
        if (n == 0 && m == 0) {
            break;
        }

        if (m > n - 1) {
            int a, b;
            for (int i = 1; i <= m; i++) {
                scanf("%d %d", &a, &b);
            }
            printf("No\n");
            continue;
        }

        make_set(n);

        for (int i = 1; i <= m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            union_set(a, b);
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (f[i] == i) {
                ans += 1;
            }
        }

        if (ans == 1) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}
