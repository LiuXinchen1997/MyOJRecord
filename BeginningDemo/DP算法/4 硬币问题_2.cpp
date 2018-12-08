#include <iostream>
#include <cstdio>

using namespace std;

#define N 10005
#define INF (1<<30)
int T[N];
int c[21];

int min_of_2(int x, int y)
{
    return (x < y ? x : y);
}

int main()
{
    int n, m;
    scanf("%d %d", &m, &n);

    for (int i = 1; i <= n; i++) { scanf(" %d", &c[i]); }
    for (int i = 0; i <= m; i++) { T[i] = INF; }
    T[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = c[i]; j <= m; j++) {
            T[j] = min_of_2(T[j], T[j-c[i]] + 1);
        }
    }

    cout << T[m] << endl;
    return 0;
}