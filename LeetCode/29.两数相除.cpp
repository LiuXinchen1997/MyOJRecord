/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    int fabs(int a) {
        if (a > 0) { return -a; }
        return a;
    }

    int divide(int dividend, int divisor) {
        if (0 == dividend) { return 0; }
        if (1 == divisor) { return dividend; }
        if (-1 == divisor) {
            if (dividend == INT_MIN) { return INT_MAX; }
            return -dividend;
        }

        int sign = 1;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) { sign = -1; }
        dividend = fabs(dividend);
        divisor = fabs(divisor);
        if (dividend > divisor) { return 0; }
        if (dividend == divisor) { return sign; }

        // divisor != INT_MIN
        divisor = -divisor;
        int cur = 0;
        while (true) {
            int tmp = 0;
            while (true) {
                if (0 != tmp && (divisor << (tmp-1)) > (INT_MAX >> 1)) { break; }
                if (dividend + (divisor << tmp) > 0) { break; }
                tmp += 1;
            }
            if (0 == tmp) { break; }
            tmp -= 1;
            dividend = dividend + (divisor << tmp);
            cur += (1 << tmp);
        }

        if (1 == sign) { return cur; }
        else { return -cur; }
    }
};
// @lc code=end

