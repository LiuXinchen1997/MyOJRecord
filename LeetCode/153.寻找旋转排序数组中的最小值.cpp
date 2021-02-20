/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) { return nums[0]; }
        if (nums[0] < nums[nums.size()-1]) { return nums[0]; }

        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= nums[0]) {
                if (nums[mid] > nums[mid+1]) { return nums[mid+1]; }
                else {
                    left = mid + 1;
                }
            } else {
                if (mid == 0 || nums[mid] < nums[mid-1]) { return nums[mid]; }
                else {
                    right = mid - 1;
                }
            }
        }

        return nums[0];
    }
};
// @lc code=end

