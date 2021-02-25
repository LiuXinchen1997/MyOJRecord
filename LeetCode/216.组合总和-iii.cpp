/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;

    void bianli(vector<int>& cur_res, int cur_num, int remain, int k) {
        // cur_num没有加入
        if (0 == remain) {
            if (cur_res.size() == k) {
                res.emplace_back(cur_res);
            }
            return;
        }

        if (cur_num > 9) { return; }
        
        if (remain - cur_num >= 0) {
            cur_res.push_back(cur_num);
            bianli(cur_res, cur_num+1, remain - cur_num, k);
            cur_res.pop_back();
            bianli(cur_res, cur_num+1, remain, k);
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        if (0 == k || 0 == n) { return res; }
        vector<int> cur_res;
        bianli(cur_res, 1, n, k);
        return res;
    }
};
// @lc code=end

