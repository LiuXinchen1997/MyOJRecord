#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

#define jiaozhuanhu(x) (x*acos(-1.0)/180.0)

int main()
{
    int n;
    int num = 1;
    while (cin >> n) {
        double x = 0, y = 0, ang = 0;
        for (int i = 1; i <= n; i++) {
            string str;
            cin >> str;
            if (str == "Turn") {
                double tmp;
                cin >> tmp;
                ang += tmp;
                if (ang > 360) { ang -= 360; }
            } else {
                double tmp;
                cin >> tmp;
                x = x + tmp*cos(jiaozhuanhu(ang));
                y = y + tmp*sin(jiaozhuanhu(ang));
            }
        }

        cout << "Case " << num << ": ";
        cout << fixed << setprecision(2) << x << " " << y << endl;
        ++num;
    }
    return 0;
}
