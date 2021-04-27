/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // [1: n]

        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0) {
                nums[i] = n+1;
            }
        }

        for (int i = 0; i < n; i++) {
            int num = abs(nums[i]);
            if (num <= n) {
                // 为负，意味着下标对应的数字是存在的
                nums[num-1] = -abs(nums[num-1]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        return n+1;
    }
};
// @lc code=end

