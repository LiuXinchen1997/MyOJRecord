/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
    int ans = 0;

    void dfs(vector<int>& nums, int target_s, int cur_id, int cur_s, bool is_add) {
        if (is_add) {
            cur_s += nums[cur_id];
        } else {
            cur_s -= nums[cur_id];
        }

        if (cur_id == nums.size()-1) {
            if (cur_s == target_s) { ans += 1; }
            return;
        }

        dfs(nums, target_s, cur_id+1, cur_s, true);
        dfs(nums, target_s, cur_id+1, cur_s, false);
    }


    int findTargetSumWays(vector<int>& nums, int S) {
        if (nums.size() == 0) {
            return 0;
        }
        dfs(nums, S, 0, 0, true);
        dfs(nums, S, 0, 0, false);
        return ans;
    }
};
// @lc code=end

