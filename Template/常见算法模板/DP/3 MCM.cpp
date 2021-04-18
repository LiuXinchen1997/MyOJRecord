#include <iostream>
#include <cstdio>

using namespace std;

#define N 105
#define INF (1<<30)
int n;
int p[N], m[N][N];

int min_of_2(int x, int y)
{
    return (x < y ? x : y);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf(" %d %d", &p[i-1], &p[i]);
    }

    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INF;
            for (int k = i; k <= j - 1; k++) {
                m[i][j] = min_of_2(m[i][j], m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j]);
            }
        }
    }

    cout << m[1][n] << endl;

    return 0;
}
