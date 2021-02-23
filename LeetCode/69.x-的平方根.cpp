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

        double ans = x;
        while (1) {
            double tmp = ans;
            ans = 0.5 * (ans + x / ans);
            if (fabs(ans - tmp) < 1e-7) { break; }
        }

        return int(ans);
    }
};
// @lc code=end

