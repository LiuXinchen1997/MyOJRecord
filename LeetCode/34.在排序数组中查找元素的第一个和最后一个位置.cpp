/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    int binarySearch(vector<int>& nums, int& l, int& r, int target) {
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) { return mid; }
            else if (nums[mid] < target) { l = mid + 1; }
            else { r = mid - 1; }
        }

        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int res = binarySearch(nums, l, r, target);
        
        vector<int> v(2, 0);
        if (res == -1) { v[0] = -1; v[1] = -1; return v; }

        int res_l = res;
        while (res_l >= l && nums[res_l] == target) { res_l--; }
        res_l++;

        int res_r = res;
        while (res_r <= r && nums[res_r] == target) { res_r++; }
        res_r--;

        v[0] = res_l;
        v[1] = res_r;
        return v;
    }
};
// @lc code=end

