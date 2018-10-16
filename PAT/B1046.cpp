#include <cstdio>

int main()
{
    int t;
    scanf(" %d", &t);
    int jia = 0, yi = 0;
    while (t--) {
        int a, aa, b, bb;
        scanf(" %d %d %d %d", &a, &aa, &b, &bb);

        if (aa != bb) {
            if (aa == a + b) {
                yi += 1;
            } else if (bb == a + b) {
                jia += 1;
            }
        }
    }
    printf("%d %d\n", jia, yi);

    return 0;
}
