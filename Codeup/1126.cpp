#include <cstdio>
#include <algorithm>

using namespace std;

#define N 105

struct Inter {
    int x, y;
} I[N];

bool cmp(const Inter& i1, const Inter& i2)
{
    if (i1.x != i2.x) { return i1.x > i2.x; }
    return i1.y < i2.y;
}

int main()
{
    int n;
    while (scanf("%d", &n), n != 0) {
        for (int i = 0; i < n; i++) {
            scanf(" %d %d", &I[i].x, &I[i].y);
        }
        sort(I, I + n, cmp);

        int ans = 1;
        int lastX = I[0].x;
        for (int i = 1; i < n; i++) {
            if (I[i].y <= lastX) {
                ans++;
                lastX = I[i].x;
            }
        }

        printf("%d\n", ans);
    }
}
