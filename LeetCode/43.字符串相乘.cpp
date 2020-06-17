/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
public:
    void cleanZero(string& str) {
        if (str == "0") { return; }
        int id = 0;
        while (id < str.size() && '0' == str[id]) { id++; }
        if (id == str.size()) { str = "0"; return; }

        str = str.substr(id, str.size());
    }

    void swap(string& str1, string& str2) {
        string tmp = str1;
        str1 = str2;
        str2 = tmp;
    }

    string add(string& num1, string& num2) {
        if (num1.size() < num2.size()) { swap(num1, num2); }

        string res(num1.size()+1, '0');
        int i1 = num1.size() - 1, i2 = num2.size() - 1, i3 = res.size() - 1;
        int carry = 0;
        for (; i2 >= 0 && i1 >= 0; i1--, i2--, i3--) {
            int tmp = (num1[i1] - '0' + num2[i2] - '0' + carry);
            carry = tmp / 10;
            res[i3] = (tmp % 10) + '0';
        }

        for (; i1 >= 0; i1--, i3--) {
            int tmp = (num1[i1] - '0' + carry);
            carry = tmp / 10;
            res[i3] = (tmp % 10) + '0';
        }
        if (carry) { res[i3] = '1'; }

        cleanZero(res);
        return res;
    }

    void multiply10(string& num, int times) {
        if (num == "0") { return; }
        for (int i = 0; i < times; i++) {
            num.push_back('0');
        }
    }

    string multiply_a(string& num, char a)
    {
        string res(num.size() + 1, '0');
        int num_a = a - '0';
        int carry = 0;
        int res_i = res.size() - 1;
        for (int i = num.size() - 1; i >= 0; i--, res_i--) {
            int tmp = (num[i] - '0') * num_a + carry;
            carry = tmp / 10;
            res[res_i] = (tmp % 10) + '0';
        }

        if (carry) {
            res[res_i] = carry + '0';
        }
        cleanZero(res);

        return res;
    }

    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") { return "0"; }

        string res = "0";
        cleanZero(num1);
        cleanZero(num2);

        res.reserve(num1.size() + num2.size() + 2);
        if (num1.size() < num2.size()) { swap(num1, num2); }
        for (int i = num2.size() - 1; i >= 0; i--) {
            string str = multiply_a(num1, num2[i]);
            multiply10(str, num2.size() - 1 - i);
            res = add(res, str);
        }

        return res;
    }
};
// @lc code=end
