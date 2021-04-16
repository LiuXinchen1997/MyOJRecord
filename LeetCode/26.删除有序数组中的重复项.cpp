/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            while (i+1 < nums.size() && nums[i] == nums[i+1]) {
                nums.erase(nums.begin() + i);
                len -= 1;
            }
        }

        return len;
    }
};
// @lc code=end

