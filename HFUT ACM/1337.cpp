#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

bool isNum(char ch)
{
    if (ch >= '0' && ch <= '9') {
        return true;
    }

    return false;
}

int main()
{
    int T;
    scanf("%d", &T);

    char exp[15];
    while (T--) {
        scanf("%s", exp);
        int len = strlen(exp);

        int nums[3] = {0, 0, 0};
        for (int i = 0, j = 0; i < len; i++) {
            if (isNum(exp[i])) {
                nums[j] = nums[j] * 10 + (exp[i] - '0');
            } else {
                ++j;
            }
        }

        printf("%d\n", nums[0]+nums[1]-nums[2]);
    }
}
