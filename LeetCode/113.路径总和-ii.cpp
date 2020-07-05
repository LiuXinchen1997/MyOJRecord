/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void solve(vector<vector<int>>& res, int& sum, TreeNode* root,
     vector<int> cur, int cur_sum) {
        if (!root) { return; }

        cur.push_back(root->val);
        cur_sum += root->val;
        if (root->left == NULL && root->right == NULL) {
            if (cur_sum == sum) { res.push_back(cur); }
            return;
        }
        solve(res, sum, root->left, cur, cur_sum);
        solve(res, sum, root->right, cur, cur_sum);
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (!root) { return res; }
        solve(res, sum, root, vector<int>(), 0);

        return res;
    }
};
// @lc code=end

