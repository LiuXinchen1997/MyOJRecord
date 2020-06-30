/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    bool check(char s1, char s2) {
        if ('1' == s1) { return true; }
        if ('2' == s1 && '0' <= s2 && s2 <= '6') { return true; }
        return false;
    }

    int numDecodings(string s) {
        if (0 == s.size()) { return 0; }
        int id = 0;
        if ('0' == s[0]) { return 0; }
        
        vector<int> dp(s.size() + 1, 0);
        dp[1] = 1;
        if (s.size() >= 2) {
            if (s[1] != '0') { dp[2] += dp[1]; }
            if (check(s[0], s[1])) { dp[2] += 1; }
        }

        for (int i = 3; i <= s.size(); i++) {
            if (s[i-1] != '0') { dp[i] += dp[i-1]; }
            if (check(s[i-2], s[i-1])) {
                dp[i] += dp[i-2];
            }
        }

        return dp[s.size()];
    }
};
// @lc code=end

