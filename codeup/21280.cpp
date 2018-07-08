#include <iostream>
#include <algorithm>

using namespace std;

#define N 1010

int arr[N];
int dp[N];

int main()
{
    int n;
    while (cin >> n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    int k = 0;
    for (int i = 1; i < n; i++) {
        if (dp[i] > dp[k]) {
            k = i;
        }
    }
    cout << dp[k] << endl;

    }

    return 0;
}
