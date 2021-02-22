/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> new_nums(nums.size(), 0);

        for (int i = 0; i < nums.size(); i++) {
            new_nums[(i+k) % nums.size()] = nums[i];
        }

        nums.assign(new_nums.begin(), new_nums.end());
    }
};
// @lc code=end

