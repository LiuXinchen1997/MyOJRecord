/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    void solve(vector<vector<int> >& res, vector<int>& nums, vector<bool> status, vector<int> cur, int len) {
        if (len == nums.size()) {
            res.push_back(cur);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (status[i]) { continue; }
            if (i > 0 && nums[i] == nums[i-1] && !status[i-1]) { continue; }
            cur.push_back(nums[i]);
            status[i] = true;
            solve(res, nums, status, cur, len+1);
            cur.pop_back();
            status[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        if (0 == nums.size()) { return res; }
        if (1 == nums.size()) { res.push_back(nums); return res; }

        sort(nums.begin(), nums.end());
        solve(res, nums, vector<bool>(nums.size(), false), vector<int>(), 0);
        return res;
    }
};
// @lc code=end

