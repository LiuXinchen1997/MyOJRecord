/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& res, vector<int> cur,
     int id) {
        res.push_back(cur);
        if (nums.size() <= id) { return; }

        for (int i = id; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            solve(nums, res, cur, i+1);
            cur.pop_back();

            while (i + 1 < nums.size() && nums[i] == nums[i+1]) { i++; }
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        solve(nums, res, vector<int>(), 0);

        return res;
    }
};
// @lc code=end

