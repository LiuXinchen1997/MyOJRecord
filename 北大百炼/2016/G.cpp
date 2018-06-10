#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        priority_queue<int> pq;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int num;
            cin >> num;
            pq.push(-num);
        }

        int ans = 0;
        while (pq.size() != 1) {
            int n1 = pq.top();
            pq.pop();
            int n2 = pq.top();
            pq.pop();
            ans = ans + n1 + n2;
            pq.push(n1+n2);
        }
        cout << -ans << endl;
    }

    return 0;
}
