#include <iostream>

using namespace std;

int main()
{
    int s, a2, d2;
    while (cin >> s >> a2 >> d2) {
        int a1 = s, d1 = 0;
        int res = (2*a1-d2)*(2*a1-d2) - (a2-d1)*(a2-d1);

        a1 = 0;
        d1 = s;
        int res2 = (2*a1-d2)*(2*a1-d2) - (a2-d1)*(a2-d1);
        cout << (res >= res2 ? res : res2) << endl;
    }

    return 0;
}
