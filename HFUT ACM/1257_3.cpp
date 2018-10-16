#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

#define N 1005

double arr[N];

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        sort(arr, arr + n);

        double max_res = 0;
        for (int i = 1; i < n; i++){
            double sum1 = 0;
            double sum2 = 0;
            double v1 = 0;
            double v2 = 0;
            for(int j = 0; j < i; j++){
                sum1 += arr[j];
            }
            v1 = sum1 / i;
            for(int j = i; j < n; j++){
                sum2 += arr[j];
            }
            v2 = sum2 / (n-i);

            double ans1 = 0;
            double ans2 = 0;
            for (int j = 0; j < i; j++) {
                ans1 += (arr[j] - v2)*(arr[j] - v2);
            }
            for (int j = i; j < n; j++) {
                ans2 += (arr[j] - v1)*(arr[j] - v1);
            }
            max_res = max(ans1+ans2, max_res);
        }
        cout << fixed << setprecision(4) << max_res << endl;
    }

    return 0;
}
