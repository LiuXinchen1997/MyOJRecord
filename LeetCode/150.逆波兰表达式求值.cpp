/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int str2int(string str) {
        int num = 0;
        int flag = 1;
        int i = 0;
        if (str[0] == '-') {
            i = 1;
            flag = -1;
        }
        for (; i < str.size(); i++) {
            num *= 10;
            num += str[i] - '0';
        }
        num *= flag;

        return num;
    }

    bool is_num(string str) {
        if (str == "+") return false;
        if (str == "-") return false;
        if (str == "*") return false;
        if (str == "/") return false;

        return true;
    }

    int op(int a, int b, string op) {
        if (op == "+") { return a+b; }
        if (op == "-") { return a-b; }
        if (op == "*") { return a*b; }
        return a/b;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for (string token : tokens) {
            if (is_num(token)) {
                s.push(str2int(token));
            } else {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                int c = op(a, b, token);
                s.push(c);
            }
        }

        return s.top();
    }
};
// @lc code=end

