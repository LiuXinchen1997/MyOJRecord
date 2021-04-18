#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Point {
    int x, y;
    Point() {}
    Point(int xx, int yy) { x = xx; y = yy; }

    /*
    bool operator< (const Point& p)
    {
        if (this->x < p.x) { return true; }
        else if (this->x == p.x && this->y < p.y) { return true; }
        return false;
    }
    */
};

class Mycomp
{
public:
    bool operator() (const Point& p1, const Point& p2) const
    {
        if (p1.x < p2.x) { return true; }
        else if (p1.x == p2.x && p1.y < p2.y) { return true; }
        return false;
    }
};

ostream& operator<< (ostream& os, const Point& p)
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

int main()
{
    priority_queue<Point, vector<Point>, Mycomp> ppq;
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

    /*
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5);
    pq.push(3);
    pq.push(8);
    pq.push(1);

    cout << pq.top() << endl;
    */

    return 0;
}
