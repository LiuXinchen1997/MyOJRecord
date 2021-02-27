/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    // 没有好方法处理".*"的情况！！！未通过！！！
    bool isMatch(string s, string p) {
        int i1 = 0, i2 = 0;
        while (1) {
            if (i1 >= s.size() || i2 >= p.size()) { break; }

            if (p[i2] >= 'a' && p[i2] <= 'z' && i2+1 < p.size() && p[i2+1] == '*') {
                char ch = p[i2];
                i2 += 1;
                int count_in_s = 0;
                while (i1 + count_in_s < s.size() && s[i1 + count_in_s] == ch) {
                    count_in_s += 1;
                }

                int count_in_p = 0;
                while (i2 + count_in_p + 1 < p.size() && p[i2+count_in_p+1] == ch) {
                    count_in_p += 1;
                }

                i2 += count_in_p + 1;
                i1 += count_in_s;
                continue;
            }

            if (p[i2] == '.') {
                i2 += 1;
                i1 += 1;
                continue;
            }

            if (p[i2] >= 'a' && p[i2] <= 'z') {
                char ch = p[i2];
                if (p[i2] != s[i1]) { return false; }
                i1 += 1;
                i2 += 1;
            }
        }

        if (i1 < s.size() || i2 < p.size()) { return false; }
        return true;
    }
};
// @lc code=end

