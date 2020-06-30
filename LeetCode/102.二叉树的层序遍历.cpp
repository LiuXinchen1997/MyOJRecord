/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    void solve(vector<vector<int>>& res, TreeNode* root, int depth) {
        if (!root) { return; }

        if (res.size() <= depth) { res.push_back(vector<int>()); }
        res[depth].push_back(root->val);

        solve(res, root->left, depth+1);
        solve(res, root->right, depth+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) { return res; }
        solve(res, root, 0);

        return res;
    }
};
// @lc code=end

