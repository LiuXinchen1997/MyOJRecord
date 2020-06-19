/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
// 递归
class Solution {
public:
    double solve(double x, long long N) {
        if (1 == N) { return x; }
        
        double tmp = solve(x, N/2);
        tmp = tmp * tmp;
        if (N % 2 == 1) {
            return x * tmp;
        } else {
            return tmp;
        }
    }

    double myPow(double x, int n) {
        if (0 == x) { return 0; }
        if (0 == n) { return 1; }
        long long N = n;

        if (N > 0) {
            return solve(x, N);
        } else {
            return 1 / solve(x, -N);
        }
    }
};
// @lc code=end

