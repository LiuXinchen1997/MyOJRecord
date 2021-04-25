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

        int left_min = nums[0];
        multiset<int> right_all;
        for (int k = 2; k < n; ++k) { right_all.insert(nums[k]); }
        
        for (int j = 1; j < n-1; j++) {
            if (nums[j] > left_min) {
                auto it = right_all.upper_bound(left_min);
                if (it != right_all.end() && *it < nums[j]) { return true; }
            }
            left_min = min(left_min, nums[j]);
            right_all.erase(right_all.find(nums[j+1]));
        }

        return false;
    }
};
// @lc code=end

