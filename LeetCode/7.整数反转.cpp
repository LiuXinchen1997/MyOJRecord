/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        long long int num = x;
        int flag = 1;
        if (num < 0) {
            flag = -1;
            num = llabs(num);
        }

        long long int res = 0;
        int digits = 0;
        while (num) {
            digits += 1;
            res *= 10;
            res += (num % 10);

            if (flag == 1) {
                if (res > INT_MAX) { return 0; }
            } else {
                if (-res < INT_MIN) { return 0; }
            }

            num /= 10;
        }
        
        if (flag == -1) { res = -res; }
        return res;
    }
};
// @lc code=end

