#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

#define N 205
char str[N];

int main()
{
    while (gets(str)) {
        int len = strlen(str);
        reverse(str, str + len);
        puts(str);
    }

    return 0;
}
