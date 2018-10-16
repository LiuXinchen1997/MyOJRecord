#include <cstdio>
#include <cstring>

#define M 12
#define N 12

int time[M][N];
int state[M][N]; // 0为未开始腐烂，1为正在腐烂，2为腐烂完成
int m, n, x, y;

int simulate()
{
    int cost = time[x][y];
    time[x][y] = 0;
    int num = 1;
    while (true) {
        cost++;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (state[i][j] != 2 && time[i][j] == 0) {
                    num++;
                    state[i][j] = 2;
                }
            }
        }

        if (m * n == num) { return cost; }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (0 == state[i][j]) {
                    if (2 == state[i+1][j] || 2 == state[i-1][j]
                        || 2 == state[i][j+1] || 2 == state[i][j-1]) {
                        state[i][j] = 1;
                        time[i][j]--;
                    }
                } else if (1 == state[i][j]) {
                    time[i][j]--;
                    /*if (0 == time[i][j]) {
                        num++;
                        state[i][j] = 2;
                    }*/
                }
            }
        }
    }
}

int main()
{
    while (~scanf("%d%d%d%d", &m, &n, &x, &y)) {
        memset(state, 0, sizeof(state));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                scanf("%d", &time[i][j]);
            }
        }

        printf("%d\n", simulate());
    }

    return 0;
}
