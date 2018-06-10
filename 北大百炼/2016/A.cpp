#include <iostream>

using namespace std;

int main()
{
    int n;
    char jiaji;
    cin >> n >> jiaji;
    if (n <= 1000) {
        cout << 8 << endl;
    } else {
        int sum = 8;
        int c = (n-1000) / 500;
        if ((n-1000) % 500 != 0) {
            c++;
        }
        sum = sum + c * 4;
        if (jiaji == 'y') {
            sum = sum + c * 5;
        }
        cout << sum << endl;
    }

    return 0;
}
