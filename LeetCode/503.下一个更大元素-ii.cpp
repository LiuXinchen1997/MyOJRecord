/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        if (nums.size() == 0) { return ans; }
        if (nums.size() == 1) { return ans; }

        stack<int> s;
        int n = nums.size();
        for (int i = 0; i < 2 * n - 1; i++) {
            int tmp = nums[i % n];
            while (!s.empty() && tmp > nums[s.top()]) {
                ans[s.top()] = tmp;
                s.pop();
            }
            s.push(i % n);
        }

        return ans;
    }
};
// @lc code=end

