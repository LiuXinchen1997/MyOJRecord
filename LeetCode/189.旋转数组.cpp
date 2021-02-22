/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
class Solution {
public:
    void reverse(vector<int>& nums, int left, int right) {
        while (left < right) {
            swap(nums[left], nums[right]);
            left += 1;
            right -= 1;
        }
    }

    void rotate(vector<int>& nums, int k) {
        if (nums.size() <= 1 || k == 0) { return; }
        
        int n = nums.size();
        k = (k % n);

        reverse(nums, 0, n-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);
    }
};
// @lc code=end

