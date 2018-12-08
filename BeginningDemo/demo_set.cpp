#include <iostream>
#include <set>
#include <map>

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
};

ostream& operator<<(ostream& os, const Point& p)
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

int main()
{
    set<Point> ps;
    ps.insert(Point(1,1));
    ps.insert(Point(3,4));
    ps.insert(Point(2,9));
    ps.insert(Point(3,6));

    cout << ps.size() << endl;
    for (set<Point>::iterator it = ps.begin(); it != ps.end(); it++) {
        cout << *it << endl;
    }
    cout << "-----------------------" << endl;

    map<Point, int> mpi;
    mpi[Point(9,1)] = 1;
    mpi[Point(4,5)] = 5;
    mpi[Point(6,3)] = 3;
    mpi[Point(6,1)] = 7;
    mpi[Point(2,7)] = 9;
    cout << mpi.size() << endl;
    for (map<Point, int>::iterator it = mpi.begin(); it != mpi.end(); it++) {
        cout << it->first << " : " << it->second << endl;
    }

    return 0;
}
