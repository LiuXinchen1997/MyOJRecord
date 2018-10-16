#include <cstdio>

int main()
{
    int n;
    scanf(" %d", &n);

    int a1 = 0, a2 = 0, a3 = 0, a5 = 0;
    double a4sum = 0; int a4num = 0; double a4 = 0;
    int flag = 1;
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf(" %d", &tmp);

        if (tmp % 5 == 0) { if (tmp % 2 == 0) a1 += tmp; }
        else if (tmp % 5 == 1) { a2 += flag * tmp; flag = -flag; }
        else if (tmp % 5 == 2) { a3 += 1; }
        else if (tmp % 5 == 3) { a4sum += tmp; a4num += 1; }
        else if (tmp % 5 == 4) {
            if (tmp > a5) { a5 = tmp; }
        }
    }
    if (a4num != 0) {
        a4 = a4sum / a4num;
    }

    if (0 == a1) { printf("N"); }
    else { printf("%d", a1); }

    if (0 == a2) { printf(" N"); }
    else { printf(" %d", a2); }

    if (0 == a3) { printf(" N"); }
    else { printf(" %d", a3); }

    if (0 == a4num) { printf(" N"); }
    else { printf(" %.1f", a4); }

    if (0 == a5) { printf(" N"); }
    else { printf(" %d", a5); }
    printf("\n");

    return 0;
}
