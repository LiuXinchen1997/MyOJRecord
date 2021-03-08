/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */

// @lc code=start
class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        if (1 == len) { return 0; }

        vector<vector<bool>> table(len, vector<bool>(len, true));
        for (int i = len - 1; i >= 0; i--) {
            for (int j = i+1; j < len; j++) {
                table[i][j] = (s[i] == s[j] && table[i+1][j-1]);
            }
        }

        vector<int> f(len, INT_MAX);
        f[0] = 0;
        for (int i = 1; i < len; i++) {
            if (table[0][i]) { f[i] = 0; continue; }
            for (int j = 0; j < i; j++) {
                if (table[j+1][i]) {
                    f[i] = min(f[i], f[j] + 1);
                }
            }
        }

        return f[len-1];
    }
};
// @lc code=end

