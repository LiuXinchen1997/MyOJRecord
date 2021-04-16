/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.size() == 0) {
            return vector<int>();
        }
        
        vector<int> res(nums.size(), 1);
        res[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            res[i] = res[i-1] * nums[i-1];
        }

        int r = 1;
        for (int i = nums.size()-1; i >= 0; i--) {
            res[i] = res[i] * r;
            r *= nums[i];
        }

        return res;
    }
};
// @lc code=end

