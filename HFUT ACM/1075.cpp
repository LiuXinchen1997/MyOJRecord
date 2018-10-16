#include <iostream>
#include <string.h>

using namespace std;


int n, m, m_x, m_y;
int dx[9] = {0, 1, 1, 2, 2, -1, -1, -2, -2};
int dy[9] = {0, 2, -2, 1, -1, 2, -2, 1, -1};

#define N 15
int g[N][N];

bool isValid(int x, int y)
{
    if (x < 0 || x > n || y < 0 || y > m) { return false; }
    return true;
}

int main()
{
    while (cin >> n >> m >> m_x >> m_y) {
        memset(g, 0, sizeof(g));
        for (int i = 0; i <= 8; i++) {
            if (isValid(m_x+dx[i], m_y+dy[i]))
                g[m_x+dx[i]][m_y+dy[i]] = -1;
        }

        if (g[n][m] == -1) {
            cout << 0 << endl;
            continue;
        }

        g[0][0] = 1;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (g[i][j] == -1) continue;
                if (i-1 >= 0 && g[i-1][j] != -1) g[i][j] += g[i-1][j];
                if (j-1 >= 0 && g[i][j-1] != -1) g[i][j] += g[i][j-1];
            }
        }

        if (g[n][m] != -1)
            cout << g[n][m] << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
