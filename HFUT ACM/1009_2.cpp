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

void initG()
{
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            if (g[i][j] == ',') { g[i][j] = '.'; }
        }
    }
}



int bs = 0;
int has_seen = 0;
int temp_x = 1, temp_y = 1;
void bfs(int start_x, int start_y)
{
    queue<Coord> q;
    q.push(Coord(start_x, start_y, bs));
    g[start_x][start_y] = ',';

    while (1) {
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
                    g[cur_x][cur_y]=',';
                    bs = cur_b;
                    temp_x = cur_x;
                    temp_y = cur_y;
                    return;
                }
            }
        }
    }
}






int main()
{
    while(~scanf("%d%d", &m, &n)) {
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // scanf("%c", &(g[i][j]));
                cin >> g[i][j];
            }
        }

        for (int i = 1; i <= 4; i++) {
            bfs(temp_x, temp_y);
            initG();
        }

        printf("%d\n", bs);

        bs = 0;
        has_seen = 0;
        temp_x = 1;
        temp_y = 1;
    }

    return 0;
}
