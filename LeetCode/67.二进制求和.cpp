/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        string res(max(a.size(), b.size()) + 1, '0');
        
        int carry = 0;
        int i = a.size()-1, j = b.size()-1, k = res.size() - 1;
        for (; i >= 0 && j >= 0; i--, j--, k--) {
            int tmp = a[i] - '0' + b[j] - '0' + carry;
            res[k] = (tmp % 2) + '0';
            carry = tmp / 2;
        }
        while (i >= 0) {
            int tmp = a[i] - '0' + carry;
            res[k] = (tmp % 2) + '0';
            carry = tmp / 2;
            i--;
            k--;
        }
        while (j >= 0) {
            int tmp = b[j] - '0' + carry;
            res[k] = (tmp % 2) + '0';
            carry = tmp / 2;
            j--;
            k--;
        }
        if (carry) { res[k] = '1'; }

        if (res[0] == '0') { return res.substr(1, string::npos); }
        else { return res; }
    }
};
// @lc code=end

