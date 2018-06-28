#include <stdio.h>
#include <iostream>

using namespace std;

#define N 105

int f[N];
int rankk[N];
bool isRoot[N];

void make_set(int n)
{
    for (int i = 1; i <= n; i++) {
        f[i] = i;
        rankk[i] = 1;
        isRoot[i] = false;
    }
}

int find_f(int n)
{
    if (n == f[n]) {
        return f[n];
    }
    f[n] = find_f(f[n]);
    return f[n];
}

void union_set(int a, int b)
{
    int f_a = find_f(a);
    int f_b = find_f(b);
    if (rankk[a] > rankk[b]) {
        f[b] = f_a;
    } else {
        f[a] = f_b;
        if (rankk[a] == rankk[b]) {
            rankk[b]++;
        }
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    make_set(n);
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        union_set(a, b);

        for (int i = 1; i <= n; i++) {
            if (i-1) cout << " ";
            cout << f[i];
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++) {
        isRoot[f[i]] = true;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += isRoot[i];
    }
    printf("%d\n", ans);
}
