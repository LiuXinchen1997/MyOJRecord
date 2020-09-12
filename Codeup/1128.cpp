#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

#define EPS 1e-10
#define EQUALS0(x) (x < EPS && x > -EPS)

double calcCash(int d)
{
    if (d <= 4) { return 10.0; }
    else if (d <= 8) {
        return 10 + (d - 4) * 2;
    } else {
        return 18 + (d - 8) * 2.4;
    }
}

int main()
{
    int n;
    while (cin >> n && n) {
        double ans = 0;
        if (n < 4) ans = 10;
        if (n >= 4 && n <= 8) ans = 10 + (n - 4) * 2;

        /*
        if (false) {
            if (n <= 4) { ans = 10; }
            else { ans = 10 + (n - 4) * 2; }
            // ans = calcCash(n);
        } else
        */
        if (n > 8) {
            while (n >= 8) {
                ans += 18;
                n -= 8;
            }

            if (n <= 4) { /// 这里是闭区间，务必注意！！！
                ans += n * 2.4;
            } else {
                ans += 10 + (n - 4) * 2;
            }
        }


        if (ans - (int)ans == 0) {
            printf("%d\n", (int)ans);
        } else {
            printf("%.1lf\n", ans);
        }
    }

    return 0;
}


/*
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    while(cin>>n && n)
    {
        double sum = 0;

        if (n < 4) sum = 10;

        if (n >= 4 && n <= 8) sum = 10 + (n - 4) * 2;

        if (n > 8) {
            while (n >= 8) {
                sum += 18;
                n -= 8;
            }

            if (n <= 4) {
                sum += 2.4 * n;
            } else {
                sum += 10 + (n - 4) * 2;
            }
        }

        if (sum - (int)sum == 0) printf("%d\n", (int)sum);
        else printf("%.1lf\n", sum);
    }

    return 0;
}
*/
