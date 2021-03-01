/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (0 == n || 1 == n) { return 0; }

        vector l_maxs(n, 0);
        vector r_maxs(n, 0);

        l_maxs[0] = height[0];
        for (int i = 1; i < n; i++) {
            l_maxs[i] = max(l_maxs[i-1], height[i]);
        }
        r_maxs[n-1] = height[n-1];
        for (int i = n-2; i >= 0; i--) {
            r_maxs[i] = max(r_maxs[i+1], height[i]);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            res += min(l_maxs[i], r_maxs[i]) - height[i];
        }

        return res;
    }
};
// @lc code=end

