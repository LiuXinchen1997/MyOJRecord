#include <iostream>
#include <algorithm>

using namespace std;

#define N 1 << 22
int cost[N];

int main()
{
    int n, m;
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) {
            cin >> cost[i];
        }

        sort(cost+1, cost+n+1);
        cout << m / cost[1] << endl;
    }

    return 0;
}
