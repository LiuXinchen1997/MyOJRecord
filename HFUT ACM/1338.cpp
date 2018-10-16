#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cmath>

using namespace std;

int arr[10005];

bool isPrimeNum(int n)
{
    if (n <= 1) return false;

    int bounce = (int)sqrt(n) + 1;
    for (int i = 2; i < bounce; i++) {
        if (n % i == 0) return false;
    }

    return true;
}

int convert(int row, int col, int m, int n) // 将坐标转化为序列
{
    int index;
    if (col % 2 == 0) {
        index = col * m - (row-1);
    } else {
        index = (col-1) * m + row;
    }

    return index;
}

int main()
{
    int t;
    scanf("%d", &t);
    int last_max_index = 0;
    int last_max_prime = 2;

    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);

        if (last_max_index < m*n) {
            int current_num = last_max_index;
            last_max_index = m*n;
            int current_prime = last_max_prime;
            for (int i = current_num+1; i <= m*n; i++) {
                while (!isPrimeNum(current_prime)) {
                    current_prime ++;
                }
                arr[i] = current_prime;
                current_prime ++;
            }

            last_max_index = m*n;
            last_max_prime = current_prime;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                //cout << " sss " <<convert(i, j, n, m) << endl;
                cout << setw(6) << arr[convert(i, j, n, m)];
            }
            cout << endl;
        }
    }

    return 0;
}
