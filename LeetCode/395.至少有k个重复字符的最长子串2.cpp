/*
 * @lc app=leetcode.cn id=395 lang=cpp
 *
 * [395] 至少有K个重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int longestSubstring(string s, int k) {
        int ret = 0;
        int len = s.size();
        for (int t = 1; t <= 26; t++) {
            int l = 0, r = 0;
            vector<int> cnt(26, 0);
            int less = 0, total = 0;

            while (r < len) {
                cnt[s[r] - 'a'] += 1;
                if (cnt[s[r] - 'a'] == 1) {
                    less += 1;
                    total += 1;
                }

                if (cnt[s[r] - 'a'] == k) {
                    less -= 1;
                }

                while (total > t) {
                    cnt[s[l] - 'a']--;
                    if (cnt[s[l] - 'a'] == 0) {
                        less -= 1;
                        total -= 1;
                    }

                    if (cnt[s[l] - 'a'] == k-1) {
                        less += 1;
                    }
                    l++;
                }

                if (0 == less) {
                    ret = max(ret, r - l + 1);
                }
                r++;
            }
        }

        return ret;
    }
};
// @lc code=end

