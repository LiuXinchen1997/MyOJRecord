#include <iostream>
#include <cstdio>

using namespace std;

#define N 100005
int arr[N];
int p[N], L[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf(" %d", &arr[i]);
    }
    p[0] = 0;
    L[0] = -1;

    for (int i = 1; i <= n; i++) {
        int k = 0;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && p[j] > p[k]) {
                k = j;
            }
        }

        p[i] = p[k] + 1;
        L[i] = k;
    }

    cout << p[n] << endl;/

    return 0;
}
