#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int step = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n >>= 1;
        } else {
            n = ((3 * n + 1) >> 1);
        }
        step++;
    }
    cout << step << endl;

    return 0;
}
