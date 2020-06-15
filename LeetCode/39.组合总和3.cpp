/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
// dfs
class Solution {
public:
    void solve(vector<vector<int> >& res, int& target, vector<int>& candidates, vector<int> cur, int sum, int id) {
        if (sum == target) { res.push_back(cur); return; }

        for (int i = id; i < candidates.size(); i++) {
            if (sum + candidates[i] > target) { continue; }
            
            cur.push_back(candidates[i]);
            solve(res, target, candidates, cur, sum+candidates[i], i);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        if (0 == candidates.size()) { return res; }
        solve(res, target, candidates, vector<int>(), 0, 0);

        return res;
    }
};
// @lc code=end

