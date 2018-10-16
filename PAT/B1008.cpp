#include <cstdio>

#define N 105
int arr[N];

int main()
{
    int n, m;
    scanf(" %d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf(" %d", &arr[i]);
    }

    int cur = (n - (m % n)) % n;
    for (int i = 0; i < n; i++) {
        if (i) { printf(" "); }
        printf("%d", arr[cur]);
        cur++;
        if (cur == n) { cur = 0; }
    }
    printf("\n");

    return 0;
}
