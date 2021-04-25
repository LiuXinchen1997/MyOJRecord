/*
 * @lc app=leetcode.cn id=1190 lang=cpp
 *
 * [1190] 反转每对括号间的子串
 */

// @lc code=start
class Solution {
public:
    string reverseParentheses(string s) {
        while (1) {
            int i = 0;
            while (i < s.size() && s[i] != ')') { i++; }
            if (i >= s.size()) { break; }
            int j = i;
            while (j >= 0 && s[j] != '(') { j--; }

            reverse(s.begin()+j+1, s.begin()+i);
            s.erase(s.begin()+i);
            s.erase(s.begin()+j);
            i -= 2;
        }

        return s;
    }
};
// @lc code=end

