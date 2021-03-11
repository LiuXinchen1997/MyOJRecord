/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        while (x != 0 || y != 0) {
            count += ((x & 1) != (y & 1));
            x >>= 1;
            y >>= 1;
        }

        return count;
    }
};
// @lc code=end

