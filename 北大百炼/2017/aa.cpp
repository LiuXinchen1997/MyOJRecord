#include <iostream>

using namespace std;

void display(int *a, int n)
{
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << endl;
}

int main()
{
    int a[] = {4, 2, 1, 6, 3, 7, 0, 8, 12, 54, 23};

    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 10-i; j++) {
            if (a[j] > a[j+1]) {
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    cout << sizeof(a) / sizeof(int) << endl;
    display(a, 11);

    return 0;
}
