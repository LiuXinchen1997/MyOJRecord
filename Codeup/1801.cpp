#include <stdio.h>
#include <algorithm>

using namespace std;

#define N 10005
int arr[N];

int main()
{
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        sort(arr, arr + n);
        printf("%d %d\n", arr[n-1], arr[0]);
    }
}
