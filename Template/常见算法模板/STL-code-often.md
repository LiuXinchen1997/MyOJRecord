## 1 sort

第一种写法：

```c++
struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {};
};

int main()
{
    vector<Point> points;
    sort(points.begin(), points.end(), [](const Point& p1, const Point& p2) {
         if (p1.x < p2.x) { return true; }
         else if (p1.x == p2.x && p1.y < p2.y) { return true; }
         return false;
    });
}
```

第二种写法：

```c++
struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {};

    bool operator< (const Point& p) {
        if (x < p.x) { return true; }
        else if (x == p.x && y < p.y) { return true; }
        return false;
    }
};

int main()
{
    vector<Point> points;
    sort(points.begin(), points.end());
}
```


## 2 map

```c++
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
```


## 3 set

### 3.1 构造函数与遍历

```c++
struct Point {
    int x, y;
    Point() {}
    Point(int xx, int yy) { x = xx; y = yy; }

    bool operator< (const Point& p) const // 注意这里有const!!!
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
```

### 3.2 lower_bound & upper_bound

```c++
struct Point {
    int x, y;
    Point() {}
    Point(int xx, int yy) { x = xx; y = yy; }
    bool operator< (const Point& p) const {
        if (x < p.x) { return true; }
        else if (x == p.x && y < p.y) { return true; }
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
    set<Point> s;
    s.insert(Point(1,1));
    s.insert(Point(4,3));
    s.insert(Point(3,2));
    s.insert(Point(7,6));
    s.insert(Point(2,1));
    s.insert(Point(9,9));
    s.insert(Point(7,6));

    auto it = s.begin();
    for (; it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;  // (1, 1) (2, 1) (3, 2) (4, 3) (7, 6) (9, 9)

    it = s.lower_bound(Point(2,1));
    for (; it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;  // (2, 1) (3, 2) (4, 3) (7, 6) (9, 9)

    it = s.upper_bound(Point(2,1));
    for (; it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;  // (3, 2) (4, 3) (7, 6) (9, 9)

    return 0;
}
```

## 4 priority_queue

第一种写法：

```c++
struct Point {
    int x, y;
    Point() {}
    Point(int xx, int yy) { x = xx; y = yy; }
    bool operator< (const Point& p) const { // 注意这里有const!!!
        if (x < p.x) { return true; }
        else if (x == p.x && y < p.y) { return true; }
        return false;
    }
};

int main()
{
    priority_queue<Point> pq;
}
```

第二种写法：

```c++
struct Point {
    int x, y;
    Point() {}
    Point(int xx, int yy) { x = xx; y = yy; }
};

bool mycomp (const Point& p1, const Point& p2)
{
    if (p1.x < p2.x) { return true; }
    else if (p1.x == p2.x && p1.y < p2.y) { return true; }
    return false;
}

int main()
{
    priority_queue<Point, vector<Point>, decltype(&mycomp)> ppq(mycomp);
}
```

第三种写法：

```c++
struct Point {
    int x, y;
    Point() {}
    Point(int xx, int yy) { x = xx; y = yy; }
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

int main()
{
    priority_queue<Point, vector<Point>, Mycomp> ppq;

    /*
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5);
    pq.push(3);
    pq.push(8);
    pq.push(1);

    cout << pq.top() << endl;
    */
}
```


## 5 类型转换

```c++
// 字符和数字之间的转化
// clang++ 7.0.1

#include <iostream>

using namespace std;

int main() {
    /// char -> int
    char numChar = '9';
    cout << "char -> int" << endl << static_cast<int>(numChar - 48) << endl << endl;
    // int = char - 48

    /// int -> char
    int numInt = 4;
    cout << "int -> char" << endl << static_cast<char>(numInt + 48) << endl << endl;

    /// char* -> int
    const char* charGroup = "123";
    cout << "char* -> int" << endl << atoi(charGroup) << endl << endl;

    /// int -> char*
    numInt = 123;
    auto charGroup2 = to_string(numInt).c_str();
    cout << "int -> char*" << endl << charGroup2 << endl << endl;

    /// char* -> double
    const char* charGroup3 = "123.123";
    cout << "char* -> double" << endl << atof(charGroup3) << endl << endl;

    /// double -> char*
    double numDouble = 123.123;
    const char* charGroup4 = to_string(numDouble).c_str();
    cout << "double -> char*" << endl << charGroup4 << endl << endl;

    /// string -> int/double
    string numStr = "666";
    cout << "string -> int/double" << endl << stoi(numStr) << endl << endl;
    // double 用 stod()

    /// int/double -> string
    double numDouble2 = 123.123;
    cout << "int/double -> string" << endl << to_string(numDouble2) << endl << endl;

    /// string -> char*
    string str = "ganlerkiller";
    cout << "string -> char[]" << endl << str.c_str() << endl << endl;

    /// char* -> string
    const char* cstr = "ganlerganler";
    string str2(cstr);
    cout << "char* -> string" << endl << cstr << endl << endl;
}

/*
char -> int
9

int -> char
4

char* -> int
123

int -> char*
123

char* -> double
123.123

double -> char*
123.123000

string -> int/double
666

int/double -> string
123.123000

string -> char[]
ganlerkiller

char* -> string
ganlerganler
*/
```

此外，还有万能转换法：`to_string()`!!!
