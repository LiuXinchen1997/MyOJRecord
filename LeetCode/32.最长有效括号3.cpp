/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        if (0 == s.size()) { return 0; }

        int l = 0, r = 0;
        int max_len = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                l += 1;
            } else if (s[i] == ')') {
                r += 1;
                if (l == r) {
                    if (max_len < l * 2) { max_len = l * 2; }
                }
                if (l < r) {
                    l = 0;
                    r = 0;
                }
            }
        }

        l = 0;
        r = 0;
        for (int i = s.size(); i >= 0; i--) {
            if (s[i] == ')') {
                r += 1;
            } else if (s[i] == '(') {
                l += 1;
                if (l == r) {
                    if (max_len < l * 2) { max_len = l * 2; }
                }
                if (l > r) {
                    l = 0;
                    r = 0;
                }
            }
        }
        return max_len;
    }
};
// @lc code=end

