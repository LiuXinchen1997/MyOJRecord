#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Point {
    int x, y;
    Point() {}
    Point(int xx, int yy) { x = xx; y = yy; }
};

struct Mycomp {
    bool operator() (const Point& p1, const Point& p2)
    {
        bool flag = false;
        if (p1.x >= p2.x) { flag = true; }
        else if (p1.x == p2.x && p1.y >= p2.y) { flag = true; }

        return !flag;
    }
} mycomp;

bool myfunction(const Point& p1, const Point& p2)
{
    bool flag = false;
    if (p1.x >= p2.x) { flag = true; }
    else if (p1.x == p2.x && p1.y >= p2.y) { flag = true; }

    return flag;
}

ostream& operator<< (ostream& os, Point& p)
{
    os << p.x << " " << p.y << endl;
    return os;
}

int main()
{
    vector<Point> vs;
    vs.push_back(Point(7,4));
    vs.push_back(Point(4,4));
    vs.push_back(Point(5,3));
    vs.push_back(Point(5,2));
    vs.push_back(Point(8,2));
    vs.push_back(Point(1,5));
    vs.push_back(Point(2,4));
    vs.push_back(Point(3,2));
    vs.push_back(Point(3,4));

    sort(vs.begin(), vs.end(), mycomp);
    for (int i = 0; i < vs.size(); i++) {
        cout << vs[i] << endl;
    }

    cout << "-------------------------------" << endl;

    sort(vs.begin(), vs.end(), myfunction);
    for (int i = 0; i < vs.size(); i++) {
        cout << vs[i] << endl;
    }
}
