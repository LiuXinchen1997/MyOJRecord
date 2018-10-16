#include <iostream>
#include <cstdio>
#include <cmath>

#define PI acos(-1.0)

using namespace std;

double calc(double x1, double y1, double r1, double x2, double y2, double r2) {
    double dist = sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
    if (dist >= r1 + r2) { return 0.0; } // 相离
    if (dist <= r1 - r2) { return PI*r2*r2; }

    // 相交的情况
    // r1圆的半圆心角
    double an1 = acos((r1*r1+dist*dist-r2*r2) / (2*r1*dist));
    double an2 = acos((r2*r2+dist*dist-r1*r1) / (2*r2*dist));
    return 2*an1*r1*r1*0.5 + 2*an2*r2*r2*0.5 - sin(an1)*r1*2*dist/2;
}

int main()
{
    double x1, y1, r1, x2, y2, r2;
    while (cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2) {
        // r1是大圆，r2是小圆
        if (r1 < r2) {
            double tmp = r1; r1 = r2; r2 = tmp;
            tmp = x1; x1 = x2; x2 = tmp;
            tmp = y1; y1 = y2; y2 = tmp;
        }

        double area = calc(x1, y1, r1, x2, y2, r2);
        printf("%.2f\n", area);
    }

    return 0;
}
