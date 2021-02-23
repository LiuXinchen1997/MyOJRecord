/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */

// @lc code=start
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (0 == m) { return 0; }
        if (m == n) { return m; }

        int times = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            times += 1;
        }

        m <<= times;
        return m;
    }
};
// @lc code=end

