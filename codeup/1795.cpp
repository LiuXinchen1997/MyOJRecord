#include <iostream>
using namespace std;

#define N 35

int arr[N];

int main()
{
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= 30; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }

    int n;
    while (cin >> n) {
        cout << arr[n] << endl;
    }
}
