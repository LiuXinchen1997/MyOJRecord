#include <iostream>
#include <cmath>
using namespace std;

int abs(int n)
{
    if (n < 0) { return -n; }
    return n;
}

int main()
{
    int b, n;
    cin >> b >> n;
    while (b!=0 && n!=0) {
        int a = 1;
        while (true) {
            if (abs(pow(a, n)-b) <= abs(pow(a+1, n)-b)) {
                break;
            }
            a++;
        }
        cout << a << endl;

        cin >> b >> n;
    }

    return 0;
}
