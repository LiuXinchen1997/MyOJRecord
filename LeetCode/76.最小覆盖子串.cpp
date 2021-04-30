/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    unordered_map<char, int> ori, cnt;

    bool check() {
        for (const auto it : ori) {
            if (cnt[it.first] < it.second) { return false; }
        }
        return true;
    }

    string minWindow(string s, string t) {
        for (const char& ch : t) {
            ori[ch] += 1;
        }

        int len = INT_MAX, ans_l = -1;
        int lid = 0, rid = 0;
        while (rid < s.size()) {
            if (ori.count(s[rid])) { cnt[s[rid]] += 1; }

            while (check() && lid <= rid) {
                if (rid - lid + 1 < len) {
                    len = rid - lid + 1;
                    ans_l = lid;
                }
                if (ori.count(s[lid])) {
                    cnt[s[lid]] -= 1;
                }
                lid += 1;
            }
            rid += 1;
        }

        return ans_l == -1 ? string() : s.substr(ans_l, len);
    }
};
// @lc code=end

