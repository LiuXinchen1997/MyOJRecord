#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n != 0) {
        int* arr = new int[2*n+1];
        int sum = 0;
        for (int i = 1; i <= 2*n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }

        int*** dp = new int** [2*n+1];
        for (int i = 0; i <= 2*n; i++) {
            dp[i] = new int* [n+1];
            for (int j = 0; j <= n; j++) {
                dp[i][j] = new int [sum/2+4];
                fill(dp[i][j], dp[i][j]+sum/2+4, 0);
            }
        }

        // dp表示A组的总数值
        for (int i = 1; i <= 2*n; i++) { // 考虑前第i个数
            for (int j = 1; j <= min(i, n); j++) { // 其中j个数放在A组
                for (int num = 0; num <= sum/2; num++) {
                    if (num < arr[i]) {
                        dp[i][j][num] = dp[i-1][j][num];
                    } else {
                        dp[i][j][num] = max(dp[i-1][j-1][num-arr[i]]+arr[i], dp[i-1][j][num]);
                    }
                }
            }
        }

        int a_sum = dp[2*n][n][sum/2];
        int b_sum = sum - a_sum;
        cout << fixed << setprecision(1) << (double)abs(a_sum-b_sum) / n << endl;

        delete []arr;
        for (int i = 0; i < 2*n+1; i++) {
            for (int j = 0; j < n+1; j++) {
                delete []dp[i][j];
            }
            delete []dp[i];
        }
        delete []dp;
        cin >> n;
    }

    return 0;
}
