#include <iostream>

using namespace std;

#define N 105
int nums[N];

bool isEven(int num)
{
    return (num % 2 == 0);
}

int main()
{
    int n;
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            cin >> nums[i];
        }

        bool even = true; /// true表示大多数是偶数，false表示大多数是奇数
        int even_count = 0;
        int odd_count = 0;
        for (int i = 1; i <= 3; i++) {
            if (isEven(nums[i])) { even_count++; } else { odd_count++; }
        }

        if (odd_count >= 2) { even = false; }

        if (even) {
            for (int i = 1; i <= n; i++) {
                if (!isEven(nums[i])) {
                    cout << i << endl;
                    break;
                }
            }
        } else {
            for (int i = 1; i <= n; i++) {
                if (isEven(nums[i])) {
                    cout << i << endl;
                    break;
                }
            }
        }
    }

    return 0;
}
