/*
 * @lc app=leetcode.cn id=1689 lang=cpp
 *
 * [1689] 十-二进制数的最少数目
 */

// @lc code=start
class Solution {
public:
    int minPartitions(string n) {
        int maxn = 0;
        for (char ch : n) {
            maxn = max(ch - '0', maxn);
        }

        return maxn;
    }
};
// @lc code=end

