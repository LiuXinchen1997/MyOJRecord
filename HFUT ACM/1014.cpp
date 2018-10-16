#include <iostream>

using namespace std;

int main()
{
    __int64 n;
    __int64 jishu = 0;
    while (cin >> n) {
        jishu = 0;
        if (1 == n) {
            cout << 1 << endl;
            continue;
        }

        for (int i = 1; i*i <= n; i++) {
            if (n % i == 0) {
                if (i*i == n) {jishu++;}
                else {jishu = jishu + 2;}
            }
        }

        cout << jishu << endl;
    }

    return 0;
}
