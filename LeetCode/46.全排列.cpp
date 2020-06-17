/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
// dfs
class Solution {
public:
    void solve(vector<vector<int> >& res, vector<int>& nums, vector<bool> status, vector<int> cur, int len) {
        if (len == nums.size()) {
            res.push_back(cur);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (status[i]) { continue; }
            cur.push_back(nums[i]);
            status[i] = true;
            solve(res, nums, status, cur, len+1);
            cur.pop_back();
            status[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        if (0 == nums.size()) { return res; }
        if (1 == nums.size()) { res.push_back(nums); return res; }

        solve(res, nums, vector<bool>(nums.size(), false), vector<int>(), 0);
        return res;
    }
};
// @lc code=end

