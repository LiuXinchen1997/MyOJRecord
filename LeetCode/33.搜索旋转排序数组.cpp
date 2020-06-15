/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int binarySearch(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) { return mid; }
            if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        if (0 == nums.size()) { return -1; }
        if (1 == nums.size() && nums[0] == target) { return 0; }
        else if (1 == nums.size() && nums[0] != target) { return -1; }

        if (nums[0] < nums[nums.size() - 1]) {
            return binarySearch(nums, target);
        }

        int l = 0, r = nums.size() - 1;
        int flag = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) { return mid; }
            if (nums[mid] >= nums[0]) { 
                if (nums[mid] > nums[mid+1]) { flag = mid; break; }
                l = mid; 
            } else { 
                if (nums[mid] < nums[mid-1]) { flag = mid-1; break; }
                r = mid;
            }
        }

        if (target >= nums[0]) { l = 0; r = flag; }
        else { l = flag + 1; r = nums.size() - 1; }        
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) { return mid; }
            if (nums[mid] < target) { l = mid + 1; }
            else { r = mid - 1; }
        }

        return -1;
    }
};
// @lc code=end
