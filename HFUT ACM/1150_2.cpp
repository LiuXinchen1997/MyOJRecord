/** 未完成！！！ */
#include <iostream>
#include <vector>

using namespace std;

struct Point
{
    int x, y;
};

Point ps[50002];
vector<Point> vs; // 用于保存凸包上的点

bool cmp(Point a, Point b)
{
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

int cross(Point a, Point b, Point c)
{
    int x1 = a.x - b.x;
    int y1 = a.y - b.y;
    int x2 = c.x - b.x;
    int y2 = c.y - b.y;
    if ((x1*y2 - x2*y1) <= 0) {
        return 0;
    }
    return 1;
}

int main()
{
    int n;
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            cin >> ps[i].x >> ps[i].y;
        }

        andrew();
        rotate_kake();
    }
}
