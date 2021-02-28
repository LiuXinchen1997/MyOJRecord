/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() == 0) { return 0; }
        
        stack<int> zhan;
        zhan.push(-1);
        
        int max_len = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                zhan.push(i); 
            } else {
                zhan.pop();
                if (zhan.empty()) {
                    zhan.push(i);
                } else {
                    max_len = max(max_len, i - zhan.top());
                }
            }
        }

        return max_len;
    }
};
// @lc code=end

