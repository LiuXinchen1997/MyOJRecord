#include <iostream>
#include <stdio.h>

using namespace std;

int a[3][3];

int find1() {
    if (a[1][1] == 1) {
        return 1;
    } else if (a[1][2] == 1) {
        return 2;
    } else if (a[2][2] == 1) {
        return 3;
    } else {
        return 4;
    }
}

int x[5] = {0, 1, 1, 2, 2};
int y[5] = {0, 1, 2, 2, 1};

int dx[5] = {0, 0, 1, 0, -1};
int dy[5] = {0, 1, 0, -1, 0};

int main()
{
    int T;
    scanf("%d", &T);

    while (T--) {
        cin >> a[1][1] >> a[1][2];
        cin >> a[2][1] >> a[2][2];

        int pos_1 = find1();

        int current_x = x[pos_1];
        int current_y = y[pos_1];
        bool appear_2 = false;
        bool flag = true;
        for (int i = 1; i <= 3; i++) {
            current_x += dx[pos_1];
            current_y += dy[pos_1];

            pos_1++;
            if (pos_1 == 5) { pos_1 = 1; }

            if (a[current_x][current_y] == 2) { appear_2 = true; }
            if (a[current_x][current_y] == 3 && !appear_2) { flag = false; break; }
        }

        if (flag) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
