/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        vector<int> dp(len+1, 0);
        
        int max_len = 0;
        for (int i = 1; i < len; i++) {
            if (s[i] == '(') { continue; }
            if (s[i-1] == '(') {
                dp[i] = 2 + (i-2>=0 ? dp[i-2] : 0);
            } else if (i - dp[i-1] - 1 >= 0 && s[i - dp[i-1] - 1] == '(') {
                dp[i] = 2 + dp[i-1] + (i-dp[i-1]-2>=0 ? dp[i-dp[i-1]-2] : 0);
            }

            if (max_len < dp[i]) {
                max_len = dp[i];
            }
        }

        return max_len;
    }
};
// @lc code=end

