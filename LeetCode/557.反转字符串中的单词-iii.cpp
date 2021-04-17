/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
class Solution {
public:
    void reverseAStr(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    string reverseWords(string s) {
        int start_id = 0;
        int find_id = s.find(' ');
        while (find_id != string::npos) {
            reverseAStr(s, start_id, find_id-1);

            start_id = find_id + 1;
            find_id = s.find(' ', start_id);
        }
        reverseAStr(s, start_id, s.size()-1);

        return s;
    }
};
// @lc code=end

