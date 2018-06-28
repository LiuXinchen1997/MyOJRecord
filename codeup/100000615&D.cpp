#include <stdio.h>
#include <limits.h>

#define MAX 10000005

int f[MAX];
int rankk[MAX];
int maxx = -1;

void make_set()
{
    for (int i = 1; i < MAX; i++) {
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

void union_set(int a, int b)
{
    a = find_f(a);
    b = find_f(b);
    if (a != b) {
        f[a] = b;
        rankk[b] += rankk[a];
        if (rankk[b] > maxx) { maxx = rankk[b]; }
    }
}

int main()
{
    int n;
    while (~scanf("%d", &n)) {
        if (0 == n) {
            printf("1\n");
            continue;
        }

        maxx = -1;
        make_set();

        for (int i = 1; i <= n; i++) {
            int a, b;
            scanf(" %d %d", &a, &b);
            union_set(a, b);
        }

        printf("%d\n", maxx);
    }

    return 0;
}
