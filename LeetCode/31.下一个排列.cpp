/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void swap(int& a, int& b) { int tmp = a; a = b; b = tmp; }

    void reverse(vector<int>& nums, int l, int r) {
        for (int i = l, j = r; i < j; i++, j--) { swap(nums[i], nums[j]); }
    }

    void nextPermutation(vector<int>& nums) {
        bool changed = false;
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i] > nums[i-1]) {
                int min_j = i;
                int min_val = nums[i];
                for (int j = i + 1; j < nums.size(); j++) {
                    if (nums[j] > nums[i-1] && min_val >= nums[j]) {
                        min_val = nums[j];
                        min_j = j;
                    }
                }

                swap(nums[min_j], nums[i-1]);
                // reverse(nums, i, nums.size() - 1);
                sort(nums.begin()+i, nums.end());
                changed = true; break;
            }
        }

        if (changed) { return; }
        reverse(nums, 0, nums.size() - 1);
        return;
    }
};
// @lc code=end

