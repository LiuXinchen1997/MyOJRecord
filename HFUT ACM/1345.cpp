#include <stdio.h>
#include <iostream>

using namespace std;

bool isPrimeNumber(int num)
{
    for (int i = 2; i < num / 2 + 1; i++) {
        if (num % i == 0) return false;
    }

    return true;
}

int main()
{
    int T;
    scanf("%d", &T);

    int n, m, a, b;
    while (T--) {
        scanf("%d %d\n%d %d", &n, &m, &a, &b);

        int flag = 1; // 1正向  -1反向
        int current_id = a;
        int current_num = b;
        const int xiaoming_id = m;

        while (current_id != xiaoming_id) {
            if (isPrimeNumber(current_num)) {
                flag = -flag;
            }

            current_num++;
            current_id += flag;

            if (current_id <= 0) {
                current_id = n;
            } else if (current_id > n) {
                current_id = 1;
            }
        }

        if (isPrimeNumber(current_num)) {
            printf("duang\n");
        } else {
            printf("%d\n", current_num);
        }

    }
}
