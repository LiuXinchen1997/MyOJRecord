#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

#define N 1005
int arr[N];

int main()
{
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        sort(arr+1, arr+n+1);
        double sum1 = arr[1];
        int c1 = 1;

        double sum2 = 0;
        int c2 = n - 1;
        for (int i = 2; i <= n; i++) {
            sum2 += arr[i];
        }

        double max_res = 0;
        double v1 = sum1 / c1;
        double v2 = sum2 / c2;
        for (int i = 1; i <= c1; i++) {
            max_res = max_res + (arr[i]-v2) * (arr[i]-v2);
        }
        for (int i = c1+1; i <= n; i++) {
            max_res = max_res + (arr[i]-v1) * (arr[i]-v1);
        }

        for (int i = 2; i < n; i++) {
            sum1 += arr[i];
            c1++;
            sum2 -= arr[i];
            c2--;

            double cur_res = 0;
            v1 = sum1 / c1;
            v2 = sum2 / c2;
            for (int i = 1; i <= c1; i++) {
                cur_res = cur_res + (arr[i]-v2) * (arr[i]-v2);
            }
            for (int i = c1+1; i <= n; i++) {
                cur_res = cur_res + (arr[i]-v1) * (arr[i]-v1);
            }

            if (max_res < cur_res) { max_res = cur_res; }
        }

        cout << fixed << setprecision(4) << max_res << endl;
    }

    return 0;
}
