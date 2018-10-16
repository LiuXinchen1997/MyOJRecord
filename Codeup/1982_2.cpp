#include <iostream>
#include <map>
#include <stack>
#include <string>

using namespace std;

map<char, int> ids;

int main()
{
    ids['('] = 1;
    ids['['] = 2;
    ids['{'] = 3;
    ids['}'] = 4;
    ids[']'] = 5;
    ids[')'] = 6;

    int n;
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            stack<char> s;
            string str; cin >> str;

            for (int j = 0; j < str.size(); j++) {
                if (ids[str[j]] > 0) {
                    if (ids[str[j]] <= 3) {
                        s.push(str[j]);
                    } else {
                        if (s.empty() || ids[s.top()] + ids[str[j]] != 7) {
                            s.push(str[j]);
                            break;
                        } else {
                            s.pop();
                        }
                    }
                }
            }

            if (s.empty()) { cout << "yes" << endl; }
            else { cout << "no" << endl; }
        }
    }


    return 0;
}
