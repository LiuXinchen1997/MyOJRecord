#include <iostream>

using namespace std;

int main()
{
    int k;
    while (cin >> k) {
        int a = 1;
        for (; a <= 65; a++) {
            if ( (18+k*a) % 65 == 0 ) {
                break;
            }
        }

        if (a <= 65) {
            cout << a << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}
