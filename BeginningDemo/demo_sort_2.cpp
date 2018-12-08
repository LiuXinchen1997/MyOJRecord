#include <iostream>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
    Point() {}
    Point(int xx, int yy) { x = xx; y = yy; }
};

class MyComp
{
public:
    bool operator() (const Point& p1, const Point& p2)
    {
        if (p1.x < p2.x) { return true; }
        else if (p1.x == p2.x && p1.y < p2.y) { return true; }
        return false;
    }
} mycomp;

bool myfunc(const Point& p1, const Point& p2)
{
    if (p1.x < p2.x) { return false; }
    else if (p1.x == p2.x && p1.y < p2.y) { return false; }
    return true;
}

ostream& operator<< (ostream& os, const Point& p)
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

int main()
{
    vector<Point> vps;
    vps.push_back(Point(5,4));
    vps.push_back(Point(7,3));
    vps.push_back(Point(7,1));
    vps.push_back(Point(3,4));
    vps.push_back(Point(2,0));
    vps.push_back(Point(6,4));
    vps.push_back(Point(3,4));
    vps.push_back(Point(2,7));
    vps.push_back(Point(1,2));
    sort(vps.begin(), vps.end(), myfunc);

    for (vector<Point>::iterator it = vps.begin(); it < vps.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}
