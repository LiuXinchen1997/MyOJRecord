/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int idx = 0;
        for (int start = 0; start < s.size(); start++) {
            if (s[start] == ' ') { continue; }

            int end = start;
            while (s[end] != ' ' && end < s.size()) { end++; }

            reverse(s.begin()+start, s.begin()+end);
            
            if (idx) { s[idx++] = ' '; }
            while (start < end) {
                s[idx++] = s[start++];
            }
            start = end;
        }

        return s.substr(0, idx);
    }
};
// @lc code=end

