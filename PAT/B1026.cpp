#include <cstdio>
#include <cmath>

int main()
{
    int start, over;
    scanf(" %d %d", &start, &over);
    int span = int(round((over - start) / 100.0));

    int hour, mint, sec;
    hour = span / 3600;
    span = span % 3600;
    mint = span / 60;
    span = span % 60;
    sec = span;

    if (hour == 0) {
        printf("00");
    } else if (hour > 0 && hour <= 9) {
        printf("0%d", hour);
    } else {
        printf("%d", hour);
    }
    printf(":");

    if (mint == 0) {
        printf("00");
    } else if (mint > 0 && mint <= 9) {
        printf("0%d", mint);
    } else {
        printf("%d", mint);
    }
    printf(":");

    if (sec == 0) {
        printf("00");
    } else if (sec > 0 && sec <= 9) {
        printf("0%d", sec);
    } else {
        printf("%d", sec);
    }
    printf("\n");

    return 0;
}
