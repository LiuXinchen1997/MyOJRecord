#include <iostream>

using namespace std;

int main()
{
    double a, b, c;
    while (cin >> a >> b >> c) {
        if (1/a + 1/b + 1/c < 1) {
            cout << "Aha" << endl;
        } else {
            cout << "NoWay" << endl;
        }
    }

    return 0;
}
