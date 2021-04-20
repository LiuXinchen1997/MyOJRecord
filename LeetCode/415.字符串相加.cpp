/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        int id1 = num1.size() - 1;
        int id2 = num2.size() - 1;
        int carry = 0;
        for (; id1 >= 0 && id2 >= 0; id1--, id2--) {
            int tmp = (num1[id1] - '0' + num2[id2] - '0' + carry);
            carry = tmp / 10;
            tmp = tmp % 10;
            res = string(1, char(tmp + '0')) + res;
        }

        for (; id1 >= 0; id1--) {
            int tmp = (num1[id1] - '0' + carry);
            carry = tmp / 10;
            tmp = tmp % 10;
            res = string(1, char(tmp + '0')) + res;
        }
        for (; id2 >= 0; id2--) {
            int tmp = (num2[id2] - '0' + carry);
            carry = tmp / 10;
            tmp = tmp % 10;
            res = string(1, char(tmp + '0')) + res;
        }

        if (carry) {
            res  = string(1, '1') + res;
        }

        return res;
    }
};
// @lc code=end

