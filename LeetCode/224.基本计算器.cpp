/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
class Solution {
public:
    int str2int(string s) {
        int num = 0;
        for (int i = 0; i < s.size(); i++) {
            num *= 10;
            num += (s[i] - '0');
        }

        return num;
    }

    int calculate(string s) {
        vector<string> strs;
        for (int i = 0; i < s.size(); ) {
            if (s[i] == ' ') { i++; continue; }
            else if (s[i] == '+' || s[i] == '-' || s[i] == '(' || s[i] == ')') {
                strs.push_back(string(1, s[i])); i++;
            } else {
                string num = "";
                while (s[i] >= '0' && s[i] <= '9') {
                    num += s[i];
                    i++;
                }
                strs.push_back(num);
            }
        }

        stack<int> stk;
        int sign = 1;
        stk.push(1);
        int res = 0;
        for (string str : strs) {
            if (str == "+") {
                sign = stk.top();
            } else if (str == "-") {
                sign = -stk.top();
            } else if (str == "(") {
                stk.push(sign);
            } else if (str == ")") {
                stk.pop();
            } else {
                res += sign * str2int(str);
            }
        }

        return res;
    }
};
// @lc code=end

