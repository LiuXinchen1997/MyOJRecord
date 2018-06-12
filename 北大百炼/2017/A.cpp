#include <iostream>

using namespace std;

#define N 105
struct Point {
    Point(int xx, int yy) : x(xx), y(yy) {}
    Point() {}
    int x, y;
} ps[N];

int calcDis(int x, int y, int x0, int y0)
{
    return (y-y0)*(y-y0) + (x-x0)*(x-x0);
}

int main()
{
    int x0, y0;
    cin >> x0 >> y0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ps[i].x >> ps[i].y;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n-1; j++) {
            if (calcDis(ps[j].x, ps[j].y, x0, y0) > calcDis(ps[j+1].x, ps[j+1].y, x0, y0)) {
                Point p(ps[j].x, ps[j].y);
                ps[j].x = ps[j+1].x;
                ps[j].y = ps[j+1].y;
                ps[j+1].x = p.x;
                ps[j+1].y = p.y;
            } else if (ps[j].x > ps[j+1].x) {
                Point p(ps[j].x, ps[j].y);
                ps[j].x = ps[j+1].x;
                ps[j].y = ps[j+1].y;
                ps[j+1].x = p.x;
                ps[j+1].y = p.y;
            } else if (ps[j].y > ps[j+1].y) {
                Point p(ps[j].x, ps[j].y);
                ps[j].x = ps[j+1].x;
                ps[j].y = ps[j+1].y;
                ps[j+1].x = p.x;
                ps[j+1].y = p.y;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (i-1) { cout << ", "; }
        cout << "(" << ps[i].x << "," << ps[i].y << ")";
    }
    cout << endl;

    return 0;
}
