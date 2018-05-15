#include <iostream>
#include <queue>
using namespace std;

#define N 23
char graph[N][N];

struct Coord {
    int x, y, bs;
    Coord(int xx, int yy, int bbs) {
        x = xx;
        y = yy;
        bs = bbs;
    }
};

int dx[5] = {0, 0, 1, 0, -1};
int dy[5] = {0, 1, 0, -1, 0};

int main()
{
    int n, m;
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> graph[i][j];
            }
        }

        queue<Coord> q;
        q.push(Coord(1,1,0));
        graph[1][1] = ',';

        bool flag = false;
        while (!q.empty()) {
            Coord cur = q.front();
            if (cur.x == n && cur.y == m) {
                flag = true;
                cout << cur.bs << endl;
                break;
            }
            q.pop();
            for (int i = 1; i <= 4; i++) {
                int cur_bs = cur.bs + 1;
                int cur_x = cur.x + dx[i];
                int cur_y = cur.y + dy[i];

                if ('.' == graph[cur_x][cur_y]) {
                    q.push(Coord(cur_x, cur_y, cur_bs));
                    graph[cur_x][cur_y] = ',';
                }
            }
        }

        if (!flag) {
            cout << -1 << endl;
        }
    }

    return 0;
}
