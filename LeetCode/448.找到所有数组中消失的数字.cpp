/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            int id = (nums[i] % n) - 1;
            if (id < 0) { id = n - 1; }
            nums[id] += n;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= n) {
                ans.push_back(i+1);
            }
        }

        return ans;
    }
};
// @lc code=end

