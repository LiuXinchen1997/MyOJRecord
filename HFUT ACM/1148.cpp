#include <iostream>
#include <string.h>

using namespace std;

#define N 83
#define M 10002
unsigned __int64 F[N][M];

int main()
{
    __int64 n, m; // n个人 m对相互看见
    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0) { break; }
        if (m < n-1) {cout << 0 << endl; continue;}

        memset(F, 0, sizeof(F));
        F[1][0] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (j-1 >= 0) { F[i][j] += ((F[i-1][j-1]*2) % 9937); }
                if (j-2 >= 0) { F[i][j] += ((F[i-1][j-2]*(i-2))%9937); }
            }
        }

        cout << F[n][m] % 9937 << endl;
    }

    return 0;
}
