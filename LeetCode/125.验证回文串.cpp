/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    static const int GAP = 'A' - 'a';

    int is_alpha(char ch) {
        if (ch >= 'a' && ch <= 'z') { return 1; }
        if (ch >= 'A' && ch <= 'Z') { return 2; }
        if (ch >= '0' && ch <= '9') { return 3; }
        return 0;
    }

    bool isPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            while (i < s.size() && !is_alpha(s[i])) { i++; }
            while (j >= 0 && !is_alpha(s[j])) { j--; }
            if (i >= j) { break; }

            int type1 = is_alpha(s[i]);
            int type2 = is_alpha(s[j]);
            if (1 == type1) {
                if (1 == type2 && s[i] != s[j]) { return false; }
                if (2 == type2 && s[i] + GAP != s[j]) { return false; }
                if (3 == type2) { return false; }
            } else if (2 == type1) {
                if (1 == type2 && s[i] - GAP != s[j]) { return false; }
                if (2 == type2 && s[i] != s[j]) { return false; }
                if (3 == type2) { return false; }
            } else if (3 == type1) {
                if (1 == type2 || 2 == type2) { return false; }
                if (3 == type2 && s[i] != s[j]) { return false; }
            }
        }

        return true;
    }
};
// @lc code=end

