#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define N 1001
int c[N][N];

int lcs(string a, string b)
{
    int m = a.size(), n = b.size();
    a = ' ' + a;
    b = ' ' + b;

    for (int i = 1; i <= m; i++) { c[i][0] = 0; }
    for (int j = 1; j <= n; j++) { c[0][j] = 0; }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i] == b[j]) { c[i][j] = c[i-1][j-1] + 1; }
            else {
                c[i][j] = (c[i-1][j] > c[i][j-1] ? c[i-1][j] : c[i][j-1]);
            }
        }
    }

    return c[m][n];
}

int main()
{
    int n;
    cin >> n;
    while (n--) {
        string a, b;
        cin >> a >> b;

        cout << lcs(a, b) << endl;
    }

    return 0;
}
