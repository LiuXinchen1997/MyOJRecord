#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Point {
    Point() {}
    Point(int xx, int yy) { this->x = xx; this->y = yy; }
    int x, y;

    bool operator< (const Point& p) const
    {
        if (this->x < p.x) { return true; }
        else if (this->x == p.x && this->y < p.y) { return true; }
        return false;
    }
};

/*
bool mycomp(const Point& p1, const Point& p2)
{
    if (p1.x < p2.x) { return true; }
    else if (p1.x == p2.x && p1.y < p2.y) { return true; }
    return false;
}
*/

ostream& operator<<(ostream& os, const Point& p)
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

class Mycom {
public:
    bool operator() (const Point& p1, const Point& p2) const
    {
        if (p1.x < p2.x) { return true; }
        else if (p1.x == p2.x && p1.y < p2.y) { return true; }
        return false;
    }
};

int main()
{
    /*
    // for std::map
    bool(*fn_pt)(const Point&, const Point&) = mycomp;
    map<Point, int, bool(*)(const Point&, const Point&)> pt(fn_pt);

    pt.insert(make_pair(Point(7,1), 1));
    pt.insert(make_pair(Point(9,3), 2));
    pt.insert(make_pair(Point(5,2), 5));
    pt.insert(make_pair(Point(6,7), 2));
    pt.insert(make_pair(Point(2,8), 9));

    for (map<Point, int, bool(*)(const Point&, const Point&)>::iterator it = pt.begin(); it != pt.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    */

    /*
    // for priority queue
    priority_queue<Point, vector<Point>, Mycom> ppq;
    ppq.push(Point(7, 2));
    ppq.push(Point(4, 1));
    ppq.push(Point(3, 5));
    ppq.push(Point(8, 1));
    ppq.push(Point(2, 1));
    ppq.push(Point(3, 3));

    while (!ppq.empty()) {
        cout << ppq.top() << endl;
        ppq.pop();
    }
    */

    /*
    // for set
    set<Point> pset;
    pset.insert(Point(5,1));
    pset.insert(Point(8,7));
    pset.insert(Point(9,1));
    pset.insert(Point(8,6));
    for (set<Point>::iterator it = pset.begin(); it != pset.end(); it++) {
        cout << *it << endl;
    }

    map<Point, int> pmap;
    pmap.insert(make_pair(Point(5,1), 5));
    pmap.insert(make_pair(Point(8,7), 7));
    pmap.insert(make_pair(Point(9,1), 1));
    pmap.insert(make_pair(Point(8,6), 3));
    for (map<Point, int>::iterator it = pmap.begin(); it != pmap.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    */

    // for sort
    Mycom mycom;
    vector<Point> pv;
    pv.push_back(Point(9,6));
    pv.push_back(Point(4,3));
    pv.push_back(Point(7,2));
    pv.push_back(Point(5,3));
    pv.push_back(Point(4,5));

    sort(pv.begin(), pv.end(), mycom);
    for (vector<Point>::iterator it = pv.begin(); it != pv.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}
