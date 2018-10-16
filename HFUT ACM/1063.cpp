#include <iostream>

using namespace std;

__int64 kinds[41] = {0, 3, 8, 22, 60};

int main()
{
    for (int i = 5; i <= 40; i++) {
        kinds[i] = kinds[i-1] * 2 + kinds[i-2] * 2;
    }

    int n;
    while (cin >> n) {
        cout << kinds[n] << endl;
    }

    return 0;
}
