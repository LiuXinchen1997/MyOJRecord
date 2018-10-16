#include <iostream>

using namespace std;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int m, n;
    while (cin >> m >> n) {
        if (m > n) swap(m, n);
        long long jishu = 0, oushu = 0;
        for (int i = m; i <= n; i++) {
            if (i % 2 == 0) {
                oushu += i*i;
            } else {
                jishu += i*i*i;
            }
        }

        cout << oushu << " " << jishu << endl;
    }

    return 0;
}
