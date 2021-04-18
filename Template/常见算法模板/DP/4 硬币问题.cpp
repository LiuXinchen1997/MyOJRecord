#include <iostream>
#include <cstdio>

using namespace std;

int min_of_2(int x, int y)
{
    return (x < y ? x : y);
}

#define INF (1<<30)
#define M 22
#define N 50005

int c[M];
// int T[M][N];
int T[N];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf(" %d", &c[i]);
    }

    for (int i = 0; i <= n; i++) { T[i] = INF; }
    T[0] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = c[i]; j <= n; j++) {
            T[j] = min_of_2(T[j], T[j-c[i]] + 1);
        }
    }

    cout << T[n] << endl;
    return 0;
}
