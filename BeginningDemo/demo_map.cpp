#include <map>
#include <iostream>

using namespace std;

struct Point {
    int x, y;
    Point() {}
    Point(int xx, int yy) { x = xx; y = yy; }
    bool operator< (const Point& p) const
    {
        if (this->x < p.x) { return true; }
        else if (this->x == p.x && this->y < p.y) { return true; }
        return false;
    }
    /*
    bool operator== (const Point& p)
    {
        if (this->x == p.x && this->y == p.y) { return true; }
        return false;
    }
    */
};

bool mycomp(const Point& p1, const Point& p2)
{
    if (p1.x < p2.x) { return true; }
    else if (p1.x == p2.x && p1.y < p2.y) { return true; }
    return false;
}

ostream& operator<< (ostream& os, Point p)
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

int main()
{
    bool(*fn_pt)(const Point&, const Point&) = mycomp;

    map<Point, int, bool(*)(const Point&, const Point&)> pi(fn_pt);
    pi.insert(make_pair(Point(1,1), 1));
    pi[Point(1,2)] = 2;
    pi.insert(make_pair(Point(3,4), 4));
    pi.insert(make_pair(Point(4,5), 3));
    pi.insert(make_pair(Point(2,1), 8));
    pi.insert(make_pair(Point(7,5), 9));
    pi.insert(make_pair(Point(7,4), 1));
    pi.insert(make_pair(Point(6,3), 1));

    cout << pi[Point(1,1)] << endl;
    cout << pi.size() << endl;

    for (map<Point, int, bool(*)(const Point&, const Point&)>::iterator it = pi.begin(); it != pi.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}
