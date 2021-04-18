#include <cstdio>
#include <iostream>

using namespace std;

#define N 1005
int arr[N];
int L[N];
int P[N];

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", arr+i);
    }

    arr[0] = 0;
    L[0] = 0;
    P[0] = -1;
    for (int i = 1; i <= n; i++) {
        int k = 0;
        for (int j = 0; j <= i - 1; j++) {
            if (L[j] > L[k] && arr[j] < arr[i]) { k = j; }
        }

        L[i] = L[k] + 1;
        P[i] = k;
    }

    printf("%d\n", L[n]);

    return 0;
}
