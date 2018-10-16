#include <stdio.h>
#include <cstring>
#include <iostream>

using namespace std;

int arr[1005];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(arr,0,sizeof(arr));

        __int64 n, k, i, times;
        cin >> n >> k;

        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int f = 0;
        for (i = n - k % n, times = 0; times < n; times++, i++) {
            if (i >= n) i = 0;
            if (f++) cout << " ";
            cout << arr[i];
        }
        cout << endl;
    }

    return 0;
}
