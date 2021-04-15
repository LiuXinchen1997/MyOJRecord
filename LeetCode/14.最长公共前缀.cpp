/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    int min_of_2(int a, int b) {
        return a < b ? a : b;
    }

    string longestCommonPrefix(vector<string>& strs) {
        int len = 500;
        for (string str : strs) {
            len = min_of_2(len, str.size());
        }
        
        string res = "";
        if (strs.size() == 0) { return res; }
        for (int i = 0; i < len; i++) {
            char ch = '\0';
            bool equals = true;
            for (string str : strs) {
                if (ch == '\0') { ch = str[i]; }
                else {
                    if (ch != str[i]) { equals = false; break; }
                }
            }

            if (equals) {
                res += ch;
            } else {
                break;
            }
        }
        return res;
    }
};
// @lc code=end

