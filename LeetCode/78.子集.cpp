/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& res,
    vector<int> cur, int id) {
        if (id >= nums.size()) { return; }

        for (int i = id; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            res.push_back(cur);
            solve(nums, res, cur, i+1);  // 别再犯错误了！！！
            cur.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res(1, vector<int>());
        if (nums.size() == 0) { return res; }
        if (nums.size() == 1) { res.push_back(nums); return res; }

        solve(nums, res, vector<int>(), 0);

        return res;
    }
};
// @lc code=end

