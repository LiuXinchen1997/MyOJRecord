#include <iostream>

using namespace std;
#define EPS (1e-10)

bool equals(double a, double b)
{
    if (a-b >= -EPS && a-b <= EPS) {
        return true;
    } else {
        return false;
    }
}

struct Point {
    double x, y;
    Point(double xx, double yy) { x = xx; y = yy; }
    Point() {}
};
typedef Point Vector;

double cross(Vector a, Vector b)
{
    return a.x*b.y - a.y*b.x;
}

double dot(Vector a, Vector b)
{
    return a.x*b.x + a.y*b.y;
}

#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0
int ccw(Point p0, Point p1, Point p2)
{
    Vector a = Vector(p1.x-p0.x, p1.y-p0.y);
    Vector b = Vector(p2.x-p0.x, p2.y-p0.y);
    if (cross(a, b) > EPS) { return COUNTER_CLOCKWISE; }
    if (cross(a, b) < -EPS) { return CLOCKWISE; }
    if (dot(a, b) < -EPS) { return ONLINE_BACK; }
    if (a.x*a.x+a.y*a.y < b.x*b.x+b.y*b.y) { return ONLINE_FRONT; }
    return ON_SEGMENT;
}

bool intersect(Point p1, Point p2, Point p3, Point p4)
{
    return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
            ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

int main()
{
    Point p0, p1, p2, p3;
    while (cin >> p0.x >> p0.y >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y) {
        if (p0.x == p1.x && p2.x == p3.x) {
            cout << "No" << endl;
            continue;
        }

        if (p0.x != p1.x && p2.x != p3.x) {
            double k1 = (p1.y - p0.y) / (p1.x - p0.x);
            double k2 = (p3.y - p2.y) / (p3.x - p2.x);
            if (equals(k1, k2)) {
                cout << "No" << endl;
                continue;
            }
        }

        if (ccw(p0, p1, p2) == ON_SEGMENT || ccw(p0, p1, p3) == ON_SEGMENT
        || ccw(p2, p3, p0) == ON_SEGMENT || ccw(p2, p3, p1) == ON_SEGMENT) {
            cout << "No" << endl;
            continue;
        }

        if (intersect(p0, p1, p2, p3)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
