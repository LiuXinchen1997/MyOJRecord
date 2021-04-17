/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        for (int i = 0, j = len - 1; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }
};
// @lc code=end

