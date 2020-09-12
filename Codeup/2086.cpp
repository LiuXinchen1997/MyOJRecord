#include <iostream>
#include <algorithm>

using namespace std;

#define N 10010
int arr[N];
int dp[N];
int first[N];

int main()
{
    int n;
    while (cin >> n, n) {
        bool allNeg = true;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] > 0) { allNeg = false; }
        }

        if (allNeg) {
            cout << "0 " << arr[0] << " " << arr[n-1] << endl;
            continue;
        }

        dp[0] = arr[0];
        first[0] = 0;
        for (int i = 1; i < n; i++) {
            if (dp[i-1] + arr[i] > arr[i]) {
                dp[i] = dp[i-1] + arr[i];
                first[i] = first[i-1];
            } else {
                dp[i] = arr[i];
                first[i] = i;
            }
        }

        int k = 0;
        for (int i = 1; i < n; i++) {
            if (dp[k] < dp[i]) { k = i; }
        }
        cout << dp[k] << " " << arr[first[k]] << " " << arr[k] << endl;
    }
}
