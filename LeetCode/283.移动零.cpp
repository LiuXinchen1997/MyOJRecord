/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero_count = 0;
        for (int num : nums) {
            if (0 == num) { zero_count += 1; }
        }

        for (int id = 0; id < zero_count; id++) {
            for (int i = 0; i < nums.size() - id - 1; i++) {
                if (nums[i] == 0) {
                    swap(nums[i], nums[i+1]);
                }
            }
        }
    }
};
// @lc code=end

