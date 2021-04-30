/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        vector<int> stk;
        int cur_num = 0;
        char pre_sign = '+';
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch >= '0' && ch <= '9') { cur_num = cur_num * 10 + int(ch - '0'); }
            if (((ch < '0' || ch > '9') && ch != ' ') || i == s.size()-1) {
                switch(pre_sign) {
                    case '+':
                    stk.push_back(cur_num);
                    break;
                    case '-':
                    stk.push_back(-cur_num);
                    break;
                    case '*':
                    stk.back() *= cur_num;
                    break;
                    default:
                    stk.back() /= cur_num;
                }
                cur_num = 0;
                pre_sign = ch;
            }
        }

        int sum = 0;
        for (int num : stk) {
            sum += num;
        }
        return sum;
    }
};
// @lc code=end

