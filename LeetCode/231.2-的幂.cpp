/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) { return false; }
        
        int count = 0;
        while (n) {
            count += (n & 1);
            n >>= 1;
        }

        if (count == 1) { return true; }
        else { return false; }
    }
};
// @lc code=end

