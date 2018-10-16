/// Not AC

#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isLeft(char ch)
{
    return ch == '(' || ch == '[' || ch == '{';
}

bool isRight(char ch)
{
    return ch == ')' || ch == ']' || ch == '}';
}

bool isMatched(char zuo, char you)
{
    if (zuo == '(' && you == ')') return true;
    if (zuo == '[' && you == ']') return true;
    if (zuo == '{' && you == '}') return true;
    return false;
}

int main()
{
    int n;
    while (cin >> n) {
        stack<char> s;
        while (n--) {
            string str;
            cin >> str;
            bool flag = true;
            for (int i = 0; i < str.size(); i++) {
                if (isLeft(str[i])) {
                    s.push(str[i]);
                } else if (isRight(str[i])) {
                    if (!s.empty() && isMatched(s.top(), str[i])) { s.pop(); }
                    else { flag = false; break; }
                }
            }

            if (flag && !s.empty()) { flag = false; }

            if (flag) { cout << "yes" << endl; }
            else { cout << "no" << endl; }
        }
    }
}
