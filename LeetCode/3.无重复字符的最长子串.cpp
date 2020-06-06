/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        for (int i = 0; i < s.size(); i++) {
            int len = 0;
            char chs[256] = {0};
            for (int j = i; j < s.size(); j++) {
                if (0 == chs[s[j]]) { 
                    chs[s[j]] = 1;
                    ++len; 
                } else {
                    break;
                }
            }
            if (len > maxlen) { maxlen = len; }
        }

        return maxlen;
    }
};
// @lc code=end

