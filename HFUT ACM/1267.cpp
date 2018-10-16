#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#define N 52
__int64 f[N][N][N];

__int64 calc(__int64 a, __int64 b, __int64 c)
{
    if (a < 0 || b < 0 || c < 0) {
        return 2;
    }

    if (a > 50 || b > 50 || c > 50) {
        return 1;
    }

    if (f[a][b][c] == 0) {
        f[a][b][c] = calc(a+1,b+2,c+3) + calc(a-3, b-2, c-1);
    }
    return f[a][b][c];
}

int main()
{
    __int64 a, b, c;
    memset(f, 0, sizeof(f));

    while (~scanf("%I64d%I64d%I64d", &a, &b, &c)) {
        __int64 res = calc(a,b,c);
        printf("%I64d\n", res%10000007);
    }

    return 0;
}
