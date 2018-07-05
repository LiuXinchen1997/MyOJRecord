#include <stdio.h>
#include <string.h>

#define N 100010

char str[N];
int leftPnum[N];

int main()
{
    memset(leftPnum, 0, sizeof(leftPnum));
    scanf("%s", str);
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        leftPnum[i] = leftPnum[i-1];
        if (str[i] == 'P') {
            if (0 == i) { leftPnum[0] = 1; }
            else { leftPnum[i] = leftPnum[i-1] + 1; }
        }
    }

    int rightTnum = 0;
    int ans = 0;
    for (int i = len-1; i >= 0; i--) {
        if (str[i] == 'T') {
            if (len - 1 == i) { rightTnum = 1; }
            else { rightTnum++; }
        } else if (str[i] == 'A') {
            ans += leftPnum[i] * rightTnum;
            ans = (ans % 1000000007);
        }
    }
    printf("%d\n", ans);

    return 0;
}
