#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n, m, a, b;
    while(scanf("%d %d %d %d", &n, &m, &a, &b) != EOF) {
        int aa = n / a;
        int bb = m / b;

        aa = aa <= bb ? aa : bb;
        if (aa == 0) {
            printf("Blind my dog eyes.\n");
        } else {
            printf("%d\n", aa);
        }
    }
}
