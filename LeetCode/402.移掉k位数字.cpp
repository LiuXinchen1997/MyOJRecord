/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉K位数字
 */

// @lc code=start
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size() - k;
        string res = "";
        int pre_id = -1;
        for (int i = 0; i < n; i++) {
            char ch = '9' + 1;
            for (int id = pre_id + 1; id <= num.size() - n + i; id++) {
                if (num[id] < ch) {
                    ch = num[id];
                    pre_id = id;
                }
            }
            if (pre_id == num.size()-n+i) {
                res += num.substr(pre_id, string::npos);
                break;
            }
            res += ch;
        }
        if (res.size() == 0) { return "0"; }

        int id = -1;
        for (int i = 0; i < res.size(); i++) {
            if (res[i] == '0') { id = i; }
            else { break; }
        }
        res = res.substr(id+1, string::npos);
        return res.size() == 0 ? "0" : res;
    }
};
// @lc code=end

