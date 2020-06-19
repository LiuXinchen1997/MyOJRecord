/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
// 迭代
class Solution {
public:
    double solve(double x, long long N) {
        double res = 1.0;
        double x_tmp = x;
        while (N > 0) {
            if (N & 1) { res *= x_tmp; }
            N >>= 1;
            x_tmp *= x_tmp;
        }

        return res;
    }

    double myPow(double x, int n) {
        if (0 == x) { return 0; }
        if (0 == n) { return 1; }

        long long int N = n;
        if (N > 0) {
            return solve(x, N);
        } else {
            return 1 / solve(x, -N);
        }
    }
};
// @lc code=end

