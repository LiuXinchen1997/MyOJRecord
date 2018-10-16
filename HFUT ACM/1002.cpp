#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double k, a, b, v;
    while (cin >> k >> a >> b >> v) {
        double d2 = (b-k*a)*(b-k*a) / (1+k*k);
        double r2 = a*a + b*b;
        double x2 = r2 - d2;

        double t2 = x2 / (v*v);
        double vv = sqrt(d2 / t2);

        cout << setiosflags(ios::fixed) << setprecision(3) << vv << endl;
    }

    return 0;
}
