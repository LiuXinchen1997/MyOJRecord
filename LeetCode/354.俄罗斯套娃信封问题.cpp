/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.size() == 0) { return 0; }
        if (envelopes.size() == 1) { return 1; }

        sort(envelopes.begin(), envelopes.end(), [](const auto& e1, const auto& e2) {
            return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
        });

        int n = envelopes.size();
        int len = 1;
        vector<int> d(n + 1, 1);
        d[0] = 0;
        d[1] = envelopes[0][1];
        for (int i = 1; i < n; i++) {
            if (d[len] < envelopes[i][1]) {
                d[++len] = envelopes[i][1];
                continue;
            }

            int l = 1, r = len, pos = 0;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (envelopes[i][1] > d[mid]) {
                    l = mid + 1;
                    pos = mid;
                } else {
                    r = mid - 1;
                }
            }
            d[pos+1] = envelopes[i][1];
        }

        return len;
    }
};
// @lc code=end

