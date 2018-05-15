#include <iostream>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

struct Node
{
    int x, y;
    int step;
    Node(int xx, int yy, int s) { x = xx; y = yy; step = s; }
    Node() {}
};
Node graph[9][9];

int dx[9] = {0, 2, 2, 1, 1, -2, -2, -1, -1};
int dy[9] = {0, 1, -1, 2, -2, 1, -1, 2, -2};

bool valid(int x, int y)
{
    return x >= 1 && x <= 8 && y >= 1 && y <= 8;
}

int main()
{
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            graph[i][j].x = i;
            graph[i][j].y = j;
        }
    }
    string beg, over;
    int min_step;
    while (cin >> beg >> over) {
        queue<Node> q;
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                graph[i][j].step = 0;
            }
        }

        int beg_x = beg[0] - 'a' + 1;
        int beg_y = beg[1] - '0';
        int over_x = over[0] - 'a' + 1;
        int over_y = over[1] - '0';

        q.push(graph[beg_x][beg_y]);
        int min_s;
        while (!q.empty()) {
            int cur_s = q.front().step;
            int cur_x = q.front().x;
            int cur_y = q.front().y;
            q.pop();
            if (cur_x == over_x && cur_y == over_y) {
                min_s = cur_s;
                goto L;
            }

            for (int i = 1; i <= 8; i++) {
                int new_x = cur_x + dx[i];
                int new_y = cur_y + dy[i];
                if ( (new_x == beg_x && new_y == beg_y) || (valid(new_x, new_y) && 0 != graph[new_x][new_y].step) ) {
                    continue;
                }

                if (new_x >= 1 && new_x <= 8 && new_y >= 1 && new_y <= 8) {
                    graph[new_x][new_y].step = graph[cur_x][cur_y].step + 1;
                    q.push(graph[new_x][new_y]);
                    if (new_x == over_x && new_y == over_y) {
                        min_s = graph[new_x][new_y].step;
                        goto L;
                    }
                }
            }
        }
        L:;
        cout << "To get from " << beg << " to " << over << " takes " << min_s << " knight moves." << endl;
    }
}
