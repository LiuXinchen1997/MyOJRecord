/*
 * @lc app=leetcode.cn id=395 lang=cpp
 *
 * [395] 至少有K个重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int dfs(string& s, int l, int r, int k) {
        vector<int> cnt(26, 0);
        for (int i = l; i <= r; i++) {
            cnt[s[i] - 'a'] += 1;
        }

        char split = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0 && cnt[i] < k) {
                split = i + 'a';
                break;
            }
        }
        if (0 == split) { return r - l + 1; }
        
        int ret = 0;
        int i = l;
        while (i <= r) {
            while (i <= r && s[i] == split) { i++; }
            if (i > r) { break; }
            int start = i;
            while (i <= r && s[i] != split) { i++; }
            ret = max(ret, dfs(s, start, i-1, k));
        }

        return ret;
    }

    int longestSubstring(string s, int k) {
        return dfs(s, 0, s.size() - 1, k);
    }
};
// @lc code=end

