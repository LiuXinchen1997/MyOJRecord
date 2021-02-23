/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) { return false; }
        if (0 == x) { return true; }

        long long digits = 1;
        int weishu = 0;
        while (x / digits) {
            digits *= 10;
            weishu++;  
        }
        digits /= 10;

        int left_x = x;
        int right_x = x;
        int left = 1;
        int right = weishu;
        while (left < right) {
            int left_digit = left_x / digits;
            left_x = (left_x % digits);
            digits /= 10;
            int right_digit = (right_x % 10);
            right_x /= 10;
            if (left_digit != right_digit) { return false; }
            left++;
            right--;
        }

        return true;
    }
};
// @lc code=end

