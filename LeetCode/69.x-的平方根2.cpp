/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if (0 == x) { return 0; }
        if (1 == x || 2 == x || 3 == x) { return 1; }

        long long tmp = 1;
        while ((x/tmp) *(x/tmp) > x) {
            tmp <<= 1;
        }

        for (long long i = x/tmp; i <= x/(tmp/2); i += 1) {
            if (i*i == x) { return i; }
            if (i*i > x) { return i-1; }
        }

        return 1;
    }
};
// @lc code=end

