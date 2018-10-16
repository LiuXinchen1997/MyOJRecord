#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

#define M 14
#define N 14
int time[M][N];
bool visited[M][N];
int note[M][N];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct Node {
    int x, y;

    Node (int xx, int yy) {
        this->x = xx;
        this->y = yy;
    }
};

int main()
{
    int m, n, x, y;
    while (cin >> m >> n >> x >> y) {
        queue<Node> q;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> time[i][j];
            }
        }

        memset(note, 0, sizeof(note));
        memset(visited, false, sizeof(visited));

        int num = 1;
        visited[x][y] = true;
        note[x][y] = time[x][y];
        q.push(Node(x,y));

        while (!q.empty()) {
            int cur_x = q.top().x;
            int cur_y = q.top().y;
            q.pop();


        }
    }

    return 0;
}
