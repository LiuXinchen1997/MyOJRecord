/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    bool is_match(string& haystack, int id, string& needle) {
        for (int i = id; i < id + needle.size(); i++) {
            if (haystack[i] != needle[i-id]) { return false; }
        }
        return true;
    }

    int strStr(string haystack, string needle) {
        if (needle.size() == 0) { return 0; }
        if (haystack.size() == 0 || haystack.size() < needle.size()) { return -1; }
        
        for (int i = 0; i <= haystack.size() - needle.size(); i++) {
            if (is_match(haystack, i, needle)) { return i; }
        }
        return -1;
    }
};
// @lc code=end

