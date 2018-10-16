#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int n;
    while (cin >> n) {
        vector<int> v1;
        vector<int> v2;
        for (int i = 1; i <= n; i++) {
            int tmp; cin >> tmp;
            v1.push_back(tmp);
        }

        for (int i = 1; i <= n; i++) {
            int tmp; cin >> tmp;
            v2.push_back(tmp);
        }

        stack<int> s;
        int i1 = 0, i2 = 0;
        /*
        while (i2 < v2.size()) {
            while (s.empty() || s.top != v2[i2]) {
                if (i1 < v1.size()) {

                }
            }
        }
*/

        bool flag = true;
        while (true) {
            if (i1 < n) {
                s.push(v1[i1]); i1++;
                while (!s.empty() && s.top() == v2[i2]) {
                    s.pop();
                    i2++;
                }
            } else {
                while (i2 < n) {
                    int top = s.top();
                    if (top != v2[i2]) { flag = false; break; }
                    i2++; s.pop();
                }
                goto L;
            }
        }
        L:;

        if (flag) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}
