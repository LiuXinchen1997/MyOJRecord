/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) { return 0; }

        int left = 0;
        int right = nums.size() - 1;
        while (true) {
            int mid = (left + right) / 2;
            if (mid == 0 && nums[mid] > nums[mid+1]) { return mid; }
            if (mid == nums.size()-1 && nums[mid] > nums[mid-1]) { return mid; }
            if (nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]) { return mid; }

            if (nums[mid] < nums[mid+1]) { left = mid+1; }
            else if (nums[mid] > nums[mid+1]) { right = mid - 1; }
        }

        return left;
    }
};
// @lc code=end

