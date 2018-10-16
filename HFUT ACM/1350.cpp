#include <iostream>
#include <set>

using namespace std;

#define N 1005
int xs[N];
int ys[N];

int main()
{
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        set<double> ds;

        for (int i = 1; i <= n; i++) {
            cin >> xs[i] >> ys[i];
        }

        // 去重
        int dian_num = n;
        for (int i = 1; i <= n; i++) {
            if (xs[i] == -1) { continue; }
            for (int j = 1; j <= n; j++) {
                if (j == i) { continue; }
                if (xs[j] == -1) { continue; }
                if (xs[i] == xs[j] && ys[i] == ys[j]) {
                    xs[j] = -1; ys[j] = -1;
                    dian_num--;
                }
            }
        }

        // 横坐标相同时，斜率不存在
        int xeq = 0;
        for (int i = 1; i <= n; i++) {
            if (xs[i] == -1) { continue; }
            for (int j = i+1; j <= n; j++) {
                if (j == i) { continue; }
                if (xs[j] == -1) { continue; }
                if (xs[i] == xs[j]) { continue; }

                double new_k = (double(ys[j]-ys[i])) / (xs[j] - xs[i]);
                ds.insert(new_k);
            }
        }

        cout << ds.size() << endl;
    }

    return 0;
}
