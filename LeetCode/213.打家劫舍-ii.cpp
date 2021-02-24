/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) { return 0; }
        int n = nums.size();
        if (1 == n) { return nums[0]; }
        if (2 == n) { return max(nums[0], nums[1]); }

        return max(my_rob(nums, 0, n-2), my_rob(nums, 1, n-1));
    }

    int my_rob(vector<int>& nums, int left, int right) {
        int pre1 = nums[left];
        int pre2 = max(nums[left], nums[left+1]);
        int res = pre2;
        for (int i = left + 2; i <= right; i++) {
            res = max(pre1 + nums[i], pre2);
            pre1 = pre2;
            pre2 = res;
        }

        return res;
    }
};
// @lc code=end

