#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int *arr = new int[n+1];

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        int k;
        scanf("%d", &k);

        sort(arr+1, arr+n+1);

        int last_num = arr[n];
        for (int array_i = n-1, rank_num = 1; rank_num < k; array_i--) {
            if (arr[array_i] != last_num) {
                last_num = arr[array_i];
                rank_num++;
            }
        }
        delete[] arr;

        printf("%d\n", last_num);
    }

    return 0;
}
