/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if (0 == n) { return 0; }
        if (1 == n) { return 1; }

        int ans = 0;
        for (int i = 0; i < 2*n-1; i++) {
            int l = i/2, r = i/2+(i%2);
            while (l >= 0 && r < n && s[l] == s[r]) {
                ans++;
                l--;
                r++;
            }
        }

        return ans;
    }
};
// @lc code=end

