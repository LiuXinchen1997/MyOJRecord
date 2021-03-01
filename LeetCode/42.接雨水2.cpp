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
        int res = 0;
        for (int i = 1; i < n - 1; i++) {
            int l_max = 0;
            int r_max = 0;
            for (int j = i; j >= 0; j--) {
                l_max = max(l_max, height[j]);
            }
            for (int j = i; j < n; j++) {
                r_max = max(r_max, height[j]);
            }

            res += (min(l_max, r_max) - height[i]);
        }

        return res;
    }
};
// @lc code=end

