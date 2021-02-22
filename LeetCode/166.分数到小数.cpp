/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 */

// @lc code=start
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (denominator == 0) { return ""; }
        if (numerator == 0) { return "0"; }

        long long numerator2 = static_cast<long long>(numerator);
        long long denominator2 = static_cast<long long>(denominator);
        
        string res = "";
        if ((numerator2 > 0) ^ (denominator2 > 0)) { res += "-"; }
        
        denominator2 = llabs(denominator2);
        numerator2 = llabs(numerator2);

        res += to_string(numerator2 / denominator2);
        long long remainder = numerator2 % denominator2;
        if (remainder != 0) { res += "."; }

        map<long, int> m;
        int idx = res.size();
        while (remainder != 0) {
            if (m.count(remainder) == 1) {
                int pos = m[remainder];
                res.insert(pos, "(");
                res += ")";
                break;
            }

            m[remainder] = idx++;
            remainder *= 10;
            int fraction = remainder / denominator2;
            remainder = remainder - fraction * denominator2;
            res += to_string(fraction);
        }

        return res;
    }

    // -1
    // -2147483648
};
// @lc code=end

