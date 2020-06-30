/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (0 == nums.size()) { return false; }
        if (1 == nums.size()) {
            if (nums[0] == target) { return true; }
            else { return false; }
        }

        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) { return true; }
            if (nums[mid] == nums[l] && nums[l] == nums[r]) {
                l++; continue;
            }

            if (nums[mid] >= nums[l]) {
                if (target >= nums[l]) {
                    if (nums[mid] > target) { r = mid - 1; } 
                    else { l = mid + 1; }
                } else { l = mid + 1; }
            } else {
                if (target >= nums[l]) { r = mid - 1; }
                else {
                    if (nums[mid] > target) { r = mid - 1; } 
                    else { l = mid + 1; }
                }
            }
        }

        return false;
    }
};
// @lc code=end

