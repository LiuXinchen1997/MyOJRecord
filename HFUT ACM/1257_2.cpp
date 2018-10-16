#include <iostream>

using namespace std;

#define N 1005
int arr[N];
float sum;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }

        sort(arr+1, arr+n);
        float sum2 = 0;
        for (int i = 1; i <= n-1) {
            sum1 += arr[i]; /// i
            sum2 = sum - sum1;  /// n-i


        }
    }

    return 0;
}
