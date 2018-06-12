#include <stdio.h>

using namespace std;

int get_num(int m, int n)
{
    if (m == 0 || n == 1) { return 1; }
    if (n > m) { return get_num(m, m); }
    return get_num(m-n, n) + get_num(m, n-1);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int m, n;
        scanf("%d%d", &m, &n);
        printf("%d\n", get_num(m, n));
    }

    return 0;
}
