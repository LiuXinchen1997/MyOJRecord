#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char str[10];

int main()
{
    while (gets(str)) {
        int len = strlen(str);
        do {
            puts(str);
        } while (next_permutation(str, str + len));
        puts("");
    }
}
