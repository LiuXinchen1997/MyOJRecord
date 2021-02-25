/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
class Solution {
public:
    // 超时
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j <= i+k; j++) {
                if (j >= n) { break; }
                long long num1 = nums[i];
                long long num2 = nums[j];
                if (llabs(num1 - num2) <= t) {
                    return true;
                }
            }
        }

        return false;
    }
};
// @lc code=end

