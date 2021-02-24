/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        for (auto ch : s) {
            if ('(' == ch || '{' == ch || '[' == ch) {
                ss.push(ch);
                continue;
            }

            if (')' == ch) {
                if (ss.empty() || ss.top() != '(') { return false; }
                ss.pop();
                continue;
            }

            if (']' == ch) {
                if (ss.empty() || ss.top() != '[') { return false; }
                ss.pop();
                continue;
            }

            if ('}' == ch) {
                if (ss.empty() || ss.top() != '{') { return false; }
                ss.pop();
                continue;
            }
        }
        
        if (ss.empty()) {
            return true;
        } else {
            return false;
        }
    }
};
// @lc code=end

