#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

#define M 14
#define N 14

struct Node {
    int x, y;
    int time;

    friend bool operator< (Node a, Node b) {
        return a.time > b.time;
    }
};

Node t[M][N];
bool mark[M][N];
int dia[M][N];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool panduan(int x, int y, int m, int n)
{
    if (x >= 1 && x <= m && y >= 1 && y <= n) {
        return true;
    } else {
        return false;
    }
}

int main()
{
    int m, n, x, y;
    while (cin >> m >> n >> x >> y) {
        memset(mark, false, sizeof(mark));
        memset(dia, 0, sizeof(dia));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                t[i][j].x = i;
                t[i][j].y = j;
                cin >> dia[i][j];
            }
        }

        Node now;
        now.x = x;
        now.y = y;
        now.time = dia[x][y];
        mark[now.x][now.y] = true;
        int ind = 1;

        priority_queue<Node> q;
        q.push(now);
        while (!q.empty()) {
            now = q.top();
            q.pop();

            for (int i = 0; i <= 3; i++) {
                int new_x = now.x + dx[i];
                int new_y = now.y + dy[i];

                if (panduan(new_x, new_y, m, n) && !mark[new_x][new_y]) {
                    mark[new_x][new_y] = true;
                    t[new_x][new_y].time = dia[new_x][new_y] + now.time;
                    ind++;
                    q.push(t[new_x][new_y]);

                    if (ind == m * n) {
                        cout << t[new_x][new_y].time << endl;
                        goto L;
                    }
                }
            }
        }

        L:;
    }

    return 0;
}
