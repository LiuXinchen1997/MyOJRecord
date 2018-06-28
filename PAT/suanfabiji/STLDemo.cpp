#include <iostream>
#include <algorithm>

using namespace std;

void show_arr(int a[], int n)
{
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << endl;
}

bool cmp (int a, int b)
{
    return a > b;
}

int main()
{
    int a = 1, b = 2;
    swap(a, b);
    cout << a << " " << b << endl;

    int arr[] = {10, 11, 12, 13, 14, 15};
    reverse(arr, arr+6);
    show_arr(arr, 6);

    reverse(arr, arr+6);
    do {
        // show_arr(arr, 6);
    } while (next_permutation(arr, arr + 6));

    fill(arr, arr + 6, 233);
    show_arr(arr, 6);

    int arr2[] = {1, 2, 4, 3, 99, 54, 12};
    sort(arr2, arr2 + 7, cmp);
    show_arr(arr2, 7);

    // lower_bound()
    // upper_bound()

    return 0;
}
