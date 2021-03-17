/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
    void solve(TreeNode* root) {
        if (root == nullptr) { return; }
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = right;
        root->right = left;

        solve(root->left);
        solve(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        solve(root);
        return root;
    }
};
// @lc code=end

