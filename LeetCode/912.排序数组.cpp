/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution {
public:
    int partition(vector<int>& nums, int left, int right) {
        swap(nums[right], nums[rand() % (right - left + 1) + left]);
        int x = nums[right];
        int id = left;
        int cut = left-1; // rightest one <= x
        for (; id < right; id++) {
            if (nums[id] <= x) { 
                cut += 1;
                swap(nums[cut], nums[id]); 
            }
        }
        swap(nums[id], nums[++cut]);
        return cut;
    }

    void quick_sort(vector<int>& nums, int left, int right) {
        if (left >= right) { return; }
        int mid = partition(nums, left, right);
        quick_sort(nums, left, mid-1);
        quick_sort(nums, mid+1, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums, 0, nums.size()-1);
        return nums;
    }
};
// @lc code=end

