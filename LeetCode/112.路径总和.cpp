/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool res;

    void preorder(TreeNode* root, int curSum, int targetSum) {
        if (root == nullptr) { return; }
        if (root->left == nullptr && root->right == nullptr) {
            if (curSum == targetSum) { res = true; }
            return;
        }

        if (root->left) {
            preorder(root->left, curSum+root->left->val, targetSum);
        }
        if (root->right) {
            preorder(root->right, curSum+root->right->val, targetSum);
        }
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        res = false;
        if (root == nullptr) { return res; }
        preorder(root, root->val, targetSum);
        return res;
    }
};
// @lc code=end

