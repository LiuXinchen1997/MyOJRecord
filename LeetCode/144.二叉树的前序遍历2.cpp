/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void pre_visit(TreeNode* root, vector<int>& res) {
        res.push_back(root->val);
        if (root->left) { pre_visit(root->left, res); }
        if (root->right) { pre_visit(root->right, res); }
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) { return res; }

        pre_visit(root, res);
        return res;
    }
};
// @lc code=end

