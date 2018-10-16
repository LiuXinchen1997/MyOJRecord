#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        long long a, b, c;
        scanf(" %lld %lld %lld", &a, &b, &c);

        if (a + b > c) {
            printf("Case #%d: true\n", i);
        } else {
            printf("Case #%d: false\n", i);
        }
    }

    return 0;
}
