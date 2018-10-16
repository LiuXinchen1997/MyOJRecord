#include <cstdio>

long long getans(long a, long da)
{
    long long ans = 0;
    while (a) {
        if (a % 10 == da) {
            ans = ans * 10 + da;
        }
        a /= 10;
    }

    return ans;
}

int main()
{
    long long a, da, b, db;
    scanf(" %lld %lld %lld %lld", &a, &da, &b, &db);
    printf("%lld\n", getans(a, da) + getans(b, db));

    return 0;
}
