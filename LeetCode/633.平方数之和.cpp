/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
        long a = 0;
        long b = sqrt(c);

        while (a <= b) {
            long tmp = a*a + b*b;
            if (tmp == c) { return true; }
            else if (tmp < c) { a += 1; }
            else { b -= 1; }
        }
        return false;
    }
};
// @lc code=end

