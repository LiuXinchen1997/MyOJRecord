#include <iostream>

using namespace std;

int abs(int a, int b)
{
    if (a >= b) {
        return a - b;
    } else {
        return b - a;
    }
}

int main()
{
    int t;
    cin >> t;
    int ans[25];

    for (int i = 0; i < t; i++) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        ans[i] = abs(a*b, c*d);
    }

    for (int i = 0; i < t; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
