/*
 * @lc app=leetcode.cn id=395 lang=cpp
 *
 * [395] 至少有K个重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    // 最后一个超长样例会超时！！！
    bool check(map<char, int> m, int k) {
        for (auto it : m) {
            if (it.second != 0 && it.second < k) { return false; }
        }
        return true;
    }

    int longestSubstring(string s, int k) {
        int cur_len = s.size();

        while (cur_len >= k) {
            map<char, int> m;
            int less = 0;
            for (int i = 0; i + cur_len - 1  < s.size(); i++) {
                if (0 == i) {
                    for (int j = i; j <= i+cur_len-1; j++) {
                        if (m.count(s[j]) == 0) { 
                            m[s[j]] = 0; 
                        }
                        m[s[j]] += 1;
                    }

                    for (auto it : m) {
                        if (it.second != 0 && it.second < k) { less += 1; }
                    }
                } else {
                    m[s[i-1]] -= 1;
                    if (m[s[i-1]] == k-1) { less += 1; }

                    if (m.count(s[i+cur_len-1]) == 0) { m[s[i+cur_len-1]] = 0; }
                    m[s[i+cur_len-1]] += 1;
                    if (m[s[i+cur_len-1]] == k) { less -= 1; }
                }

                if (0 == less) {
                    return cur_len;
                }
            }

            cur_len -= 1;
        }

        return 0;
    }
};
// @lc code=end

