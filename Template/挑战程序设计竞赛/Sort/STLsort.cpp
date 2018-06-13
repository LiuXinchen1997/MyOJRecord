#include <algorithm>
#include <stdio.h>
#include <iostream>
using namespace std;

int x0, y0;
struct Point {
    Point (int xx, int yy) : x(xx), y(yy) {}
    Point () {}
    Point (Point& p1) {
        this->x = p1.x;
        this->y = p1.y;
    }
    int x, y;
} ps[105];

int calc(const Point& p)
{
    return (p.x-x0)*(p.x-x0) + (p.y-y0)*(p.y-y0);
}

bool myfun(const Point& p1, const Point& p2)
{
    if (calc(p1) < calc(p2)) { return true; }
    else if (calc(p1) == calc(p2)) {
        if (p1.x < p2.x) { return true; }
        else if (p1.x == p2.x && p1.y < p2.y) { return true; }
    }
    return false;
}

int main()
{
    scanf("%d%d", &x0, &y0);

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &(ps[i].x), &(ps[i].y));
    }

    sort(ps, ps+n, myfun);

    for (int i = 0; i < n; i++) {
        if (i) cout << ", ";
        cout << "(" << ps[i].x << "," << ps[i].y << ")";
    }
    cout << endl;

    return 0;
}
