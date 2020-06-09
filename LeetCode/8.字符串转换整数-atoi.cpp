/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string str) {
        if ("" == str) { return 0; }
        if (!isNumber(str[0]) && str[0] != ' ' && str[0] != '-' && str[0] != '+') { return 0; }
        int idx = 0;
        while (str[idx] == ' ' && idx < str.size()) { ++idx; }
        if (idx == str.size()) { return 0; }

        bool fushu = false;
        if (str[idx] == '-') { fushu = true; ++idx; }
        else if (str[idx] == '+') { ++idx; }
        if (idx == str.size()) { return 0; }
        
        int len = 0;
        while (str[idx] == '0' && idx < str.size()) { ++idx; }
        if (idx == str.size()) { return 0; }

        while (idx + len < str.size() && isNumber(str[idx+len])) { ++len; }
        if (0 == len) { return 0; }
        str = str.substr(idx, len);

        if (len > 10) { if (fushu) {return INT_MIN; } else {return INT_MAX;}}
        if (!checkInBound(str, fushu)) {
            if (fushu) { return INT_MIN; }
            else { return INT_MAX; }
        }

        long long int res = 0;
        for (int i = 0; i < str.size(); i++) {
            res *= 10;
            res += (str[i] - '0');
        }

        if (fushu) { res *= -1; }
        return res;
    }

    bool isNumber(char ch) {
        return ch >= '0' && ch <= '9';
    }

    bool checkInBound(string str, bool fushu) {
        if (str.size() > 10) { return false; }
        if (str.size() < 10) { return true; }
        
        string fushumax = "2147483648";
        string zhengshumax = "2147483647";
        if (fushu) {
            for (int i = 0; i < 10; i++) {
                if (str[i] > fushumax[i]) { return false; }
                else if (str[i] < fushumax[i]) { return true; }
            }
        } else {
            for (int i = 0; i < 10; i++) {
                if (str[i] > zhengshumax[i]) { return false; }
                else if (str[i] < zhengshumax[i]) { return true; }
            }
        }

        return true;
    }
};
// @lc code=end

