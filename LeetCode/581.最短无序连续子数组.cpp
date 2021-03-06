/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */

// @lc code=start
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if (0 == n || 1 == n) { return 0; }

        int min_num = INT_MAX, max_num = INT_MIN;
        bool flag = false;
        for (int i = 1; i < n; i++) {
            if (nums[i-1] > nums[i]) { flag = true; }
            if (flag) {
                min_num = min(min_num, nums[i]);
            }
        }
        flag = false;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i+1] < nums[i]) { flag = true; }
            if (flag) {
                max_num = max(max_num, nums[i]);
            }
        }
        
        int l, r;
        for (l = 0; l < n; l++) {
            if (nums[l] > min_num) {
                break;
            }
        }
        for (r = n - 1; r >= 0; r--) {
            if (nums[r] < max_num) {
                break;
            }
        }

        return r - l < 0 ? 0 : r - l + 1;
    }
};
// @lc code=end

