// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem5.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        if (0 == s.size()) { return ""; }
        if (1 == s.size()) { return s; }

        string s1 = processEvenCase(s);
        string s2 = processOddCase(s);

        if (s1.size() > s2.size()) { return s1; }
        else { return s2; }
    }

    string processEvenCase(string s) {
        int maxlen = 1;
        int maxlen_start = 0;

        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] != s[i+1]) { continue; }
            for (int len = 0; ; len++) {
                if (i-len < 0 || i+1+len >= s.size()) { break; }
                if (s[i-len] == s[i+1+len]) {
                    if (2*len+2 > maxlen) {
                        maxlen = 2*len+2;
                        maxlen_start = i - len;
                    }
                } else { break; }
            }
        }

        return s.substr(maxlen_start, maxlen);
    }

    string processOddCase(string s) {
        int maxlen = 1;
        int maxlen_start = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int len = 1; ; len++) {
                if (i-len < 0 || i+len >= s.size()) { break; }
                if (s[i-len] == s[i+len]) {
                    if (2*len+1 > maxlen) {
                        maxlen = 2*len+1;
                        maxlen_start = i - len;
                    }
                } else { break; }
            }
        }

        return s.substr(maxlen_start, maxlen);
    }
};
// @lc code=end

