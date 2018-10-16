#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    char str[7];
    int n;
    scanf("%d", &n);
    for (int i = 1 ; i <= n; i ++) {
        scanf("%s", str);
        printf("Case #%d: ", i);
        bool contains = false;
        for (int j = 0; j < 5; j++) {
            if (str[j] == '1' && str[j+1] == '3') {
                contains = true;
                break;
            }
        }

        if (contains) {
            printf("No, it's terrible!\n");
        } else {
            printf("Yes, I like it!\n");
        }
    }
}
