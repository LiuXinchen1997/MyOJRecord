#include <iostream>
#include <iomanip>
using namespace std;

double ps[] = {28.9, 32.7, 45.6, 78, 35, 86.2, 27.8, 43, 56, 65};

int main()
{
    int k;
    cin >> k;
    while (k--) {
        double sum = 0;
        for (int i = 0; i <= 9; i++) {
            int a;
            cin >> a;
            sum += ps[i] * a;
        }
        cout << fixed << setprecision(2) << sum << endl;
    }
    return 0;
}
