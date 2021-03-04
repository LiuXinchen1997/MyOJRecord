/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            if (count == 0) { candidate = x; }
            if (candidate == x) { count += 1; }
            else { count -= 1; }
        }

        return candidate;
    }
};
// @lc code=end

