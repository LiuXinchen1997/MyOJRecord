/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    void solve(int& n, int& k, vector<vector<int>>& res, 
    vector<int> cur, int id) {
        if (cur.size() == k) { res.push_back(cur); return; }
        if (id > n) { return; }

        for (int i = id; i <= n; i++) {
            cur.push_back(i);
            solve(n, k, res, cur, i+1);
            cur.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if (0 == k) { return res; }
        if (n == k) {
            vector<int> v;
            for (int i = 1; i <= n; i++) { v.push_back(i); }
            res.push_back(v);
            return res;
        }
        solve(n, k, res, vector<int>(), 1);

        return res;
    }
};
// @lc code=end

