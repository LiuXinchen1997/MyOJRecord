#include <iostream>
#include <set>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int x, y;
};

class mycmp
{
public:
    bool operator() (const Point& p1, const Point& p2) {
        if (p1.x != p2.x) { return p1.x > p2.x; }
        else { return p1.y > p2.y; }
    }
};

bool myfun(const Point& p1, const Point& p2)
{
    if (p1.x != p2.x) { return p1.x > p2.x; }
    else { return p1.y > p2.y; }
}

int main()
{
    set<Point, mycmp> s;
    Point p; p.x = 1; p.y = 2;
    s.insert(p);

    bool(*myfun_pt)(const Point&, const Point&) = myfun;
    set<Point, bool(*)(const Point&,const Point&)> s2(myfun_pt);

    priority_queue<Point, vector<Point>, mycmp> pq;

    Point p1;
    p1.x = 1; p1.y = 2;
    pq.push(p1);
    p1.x = 2; p1.y = 2;
    pq.push(p1);
    p1.x = 1; p1.y = 3;
    pq.push(p1);
    p1.x = 4; p1.y = 4;
    pq.push(p1);
    p1.x = 5; p1.y = 2;
    pq.push(p1);

    while (!pq.empty()) {
        cout << pq.top().x << " " << pq.top().y << endl;
        pq.pop();
    }

    return 0;
}
