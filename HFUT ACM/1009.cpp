#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

struct Coord {
    int x, y, b;
    Coord(int xx, int yy, int bb) : x(xx), y(yy), b(bb) {}
};

#define N 23
int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};
char g[N][N];
int m, n;

int main()
{
    while(~scanf("%d%d", &m, &n)) {
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // scanf("%c", &(g[i][j]));
                cin >> g[i][j];
            }
        }

        int bs = 0;
        int has_seen = 0; //一共四个

        q.push(Coord(1,1,0));
        g[1][1] = ',';

        while (!q.empty() && has_seen != 4) {
            Coord cur = q.front(); q.pop();
            int cur_b = cur.b + 1;
            for (int i = 1; i <= 4; i++) {
                int cur_x = cur.x + dx[i];
                int cur_y = cur.y + dy[i];
                if (cur_x >= 1 && cur_x <= m && cur_y >= 1 && cur_y <= n) {
                    if (g[cur_x][cur_y] == '.') {
                        g[cur_x][cur_y]=',';
                        q.push(Coord(cur_x, cur_y, cur_b));
                    } else if (g[cur_x][cur_y] == 'B') {
                        has_seen++;
                        if (has_seen == 4) { bs = cur_b; break; }
                        else {
                            q.push(Coord(cur_x, cur_y, cur_b));
                            g[cur_x][cur_y]=',';
                        }
                    }
                }
            }
        }

        printf("%d\n", bs);
    }

    return 0;
}
