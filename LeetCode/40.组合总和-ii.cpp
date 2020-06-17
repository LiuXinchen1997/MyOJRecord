/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    void solve(vector<vector<int> >& res, vector<int>& candidates, int& target, vector<int> cur, int sum, int id) {
        if (sum > target) { return; }
        if (sum == target) { 
            res.push_back(cur); return; 
        }

        for (int i = id + 1; i < candidates.size(); i++) {
            if (candidates[i] + sum > target) { continue; }
            cur.push_back(candidates[i]);
            solve(res, candidates, target, cur, sum + candidates[i], i);
            cur.pop_back();

            while (i < candidates.size() - 1 && candidates[i] == candidates[i+1]) { i++; }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        if (0 == candidates.size()) { return res; }

        sort(candidates.begin(), candidates.end());
        solve(res, candidates, target, vector<int>(), 0, -1);

        return res;
    }
};
// @lc code=end

