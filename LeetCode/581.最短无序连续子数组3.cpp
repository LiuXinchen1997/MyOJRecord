/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */

// @lc code=start
class Solution {
public:
    // 超时！！！
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if (0 == n || 1 == n) { return 0; }

        int l = n - 1;
        int r = 0;
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                if (nums[j] < nums[i]) {
                    l = min(l, i);
                    r = max(r, j);
                }
            }
        }

        return r - l < 0 ? 0 : r - l + 1;
    }
};
// @lc code=end

