#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int num;
        scanf("%d", &num);
        printf("Case #%d: ", i);

        if (num == 0) {
            printf("%d\n", 0);
            continue;
        }

        int a = 1;
        while (num % 2 == 0) {
            num /= 2;
            a *= 2;
        }

        printf("%d\n", a);
    }

    return 0;
}
