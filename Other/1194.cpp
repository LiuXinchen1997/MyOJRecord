#include <iostream>
#include <cmath>
using namespace std;

int fun(int n)
{
    int sum = 0, j, m;
    m = (-1 + sqrt(1.0+(n<<3))) / 2;
    for(int i = m+1; i > 1; i--) {
        if ((n<<1) % i) continue;
        j = (n<<1) / i;

        if (j+1-i <= 0 || (j+1-i) % 2) continue;
        sum++;
    }
    return sum;
}

int main()
{
    int n;
    while (cin >> n) {
        cout << fun(n) << endl;
    }
}
