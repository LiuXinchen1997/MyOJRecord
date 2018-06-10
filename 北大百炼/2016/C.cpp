#include <iostream>
#include <iomanip>

using namespace std;

int juzhen[11][11];

int main()
{
    int n;
    cin >> n;
    int c = (n-1) * 2 + 1;
    int mid = c / 2 + 1;

    int cur_x = 1, cur_y = 1;
    int cur_n = 1;
    for (int i = 1; i <= c; i++) {
        int lim = i;
        if (lim > mid) {
            lim = mid - (i - mid);
        }
        if (i % 2 == 1) {
            for (int j = 1; j <= lim; j++) {
                juzhen[cur_x][cur_y] = cur_n;
                if (j != lim) {
                    --cur_x;
                    ++cur_y;
                }
                ++cur_n;
            }
            if (i < mid) { ++cur_y; }
            else { ++cur_x; }
        } else {
            for (int j = 1; j <= lim; j++) {
                juzhen[cur_x][cur_y] = cur_n;
                if (j != lim) {
                    ++cur_x;
                    --cur_y;
                }
                ++cur_n;
            }
            if (i < mid) { ++cur_x; }
            else { ++cur_y; }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j-1) { cout << " "; }
            cout << setw(4) << juzhen[i][j];
        }
        cout << endl;
    }

    return 0;
}
