#include <stdio.h>
#include <algorithm>

using namespace std;

#define N 1005

#define EPS 1e-10
#define EQUALS0(x) (x <= EPS && x >= -EPS)

struct Cake {
    double kucun;
    double shoujia;
    Cake(int k, double s) : kucun(k), shoujia(s) {}
    Cake() {}
} cakes[N];

bool cmp(const Cake& cake1, const Cake& cake2)
{
    double d1 = cake1.shoujia / cake1.kucun;
    double d2 = cake2.shoujia / cake2.kucun;
    return d1 > d2;
}

int main()
{
    int n;
    double maxx;
    scanf("%d %lf", &n, &maxx);
    for (int i = 0; i < n; i++) {
        scanf(" %lf", &cakes[i].kucun);
    }
    for (int i = 0; i < n; i++) {
        scanf(" %lf", &cakes[i].shoujia);
    }
    sort(cakes, cakes + n, cmp);

    double benifit = 0;
    for (int i = 0; i < n; i++) {
        if (EQUALS0(maxx)) { break; }
        if (cakes[i].kucun <= maxx) {
            benifit += cakes[i].shoujia;
            maxx -= cakes[i].kucun;
        } else {
            benifit += maxx * cakes[i].shoujia / cakes[i].kucun;
            maxx = 0;
        }
    }
    printf("%.2lf\n", benifit);

    return 0;
}
