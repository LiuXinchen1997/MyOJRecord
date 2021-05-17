/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> cnt(26, 0);
        vector<int> cands;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            cnt[ch-'a'] += 1;
            if (cnt[ch-'a'] == 1) { cands.push_back(i); }
        }

        for (int cand : cands) {
            if (cnt[s[cand]-'a'] == 1) { return cand; }
        }
        return -1;
    }
};
// @lc code=end

