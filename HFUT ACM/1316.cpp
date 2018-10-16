#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int nums[1002];

int main()
{
    int n;
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", nums+i);
        }

        sort(nums, nums+n);
        if (n % 2 == 0) {
            int mid = n / 2;
            float result = ((float)(nums[mid]) + (float)(nums[mid+1])) / 2;
            printf("%.2f\n", result);
        } else {
            int mid = n / 2 + 1;
            float result = (float)(nums[mid]);
            printf("%.2f\n", result);
        }
    }

    return 0;
}
