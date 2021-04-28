/*
 * @lc app=leetcode.cn id=424 lang=cpp
 *
 * [424] 替换后的最长重复字符
 */

// @lc code=start
class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0;
        vector<int> count(26, 0);
        
        int maxn = 0;
        for (char ch : s) {
            count[ch - 'A'] += 1;
            maxn = max(maxn, count[ch - 'A']);
            if (right - left + 1 - maxn > k) {
                count[s[left] - 'A'] -= 1;
                left += 1;
            }
            right += 1;
        }

        return right - left;
    }
};
// @lc code=end

