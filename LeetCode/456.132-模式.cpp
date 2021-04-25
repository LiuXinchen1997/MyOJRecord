/*
 * @lc app=leetcode.cn id=456 lang=cpp
 *
 * [456] 132 模式
 */

// @lc code=start
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) { return false; }

        stack<int> stk;
        stk.push(nums[n-1]);
        int max_k = INT_MIN;
        for (int i = n-2; i >= 0; i--) {
            // 考虑nums[i]做i
            if (nums[i] < max_k) { return true; }
            
            // nums[i]做不了i，那考虑nums[i]做j，即找出单调栈中小于nums[i]的最大那个数作为k
            // 即考虑当前能取到的最大的k
            while (!stk.empty() && stk.top() < nums[i]) {
                max_k = stk.top();
                stk.pop();
            }
            if (nums[i] > max_k) { // 保证max_k是越来越大的
                stk.push(nums[i]);
            }
        }

        return false;
    }
};
// @lc code=end

