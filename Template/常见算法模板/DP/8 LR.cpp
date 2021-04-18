#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

#define N 1405

int max_of_2(int x, int y)
{
    return (x > y ? x : y);
}

struct Rect {
    int height, pos;
};

int getLargestRect(int size, int buffer[])
{
    stack<Rect> s;
    int maxv = 0;
    buffer[size] = 0;

    for (int i = 0; i <= size; i++) {
        Rect rect;
        rect.height = buffer[i];
        rect.pos = i;
        if (s.empty()) {
            s.push(rect);
        } else {
            if (s.top().height < rect.height) {
                s.push(rect);
            } else if (s.top().height > rect.height) {
                int target = i;
                while (!s.empty() && s.top().height >= rect.height) {
                    Rect pre = s.top(); s.pop();
                    int area = pre.height * (i - pre.pos);
                    maxv = max_of_2(maxv, area);
                    target = pre.pos;
                }
                rect.pos = target;
                s.push(rect);
            }
        }
    }

    return maxv;
}

int buffer[N][N], dp[N][N];
int h, w;

int getLargestRect()
{
    // 获得每一行的直方图数据
    for (int j = 0; j < w; j++) {
        for (int i = 0; i < h; i++) {
            if (buffer[i][j]) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = ((i > 0) ? dp[i-1][j] + 1 : 1);
            }
        }
    }

    int maxv = 0;
    for (int i = 0; i < h; i++) {
        maxv = max_of_2(maxv, getLargestRect(w, buffer[i]));
    }

    return maxv;
}

int main()
{
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf(" %d", &buffer[i][j]);
        }
    }

    cout << getLargestRect() << endl;

    return 0;
}
