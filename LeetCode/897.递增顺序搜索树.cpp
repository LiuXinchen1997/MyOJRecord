/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序搜索树
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
    TreeNode* pre_node;

    void inorder(TreeNode* root) {
        if (root->left) { inorder(root->left); }

        root->left = nullptr;
        pre_node->right = root;
        pre_node = root;

        if (root->right) { inorder(root->right); }
    }

    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy_node = new TreeNode(-1);
        pre_node = dummy_node;
        inorder(root);

        return dummy_node->right;
    }
};
// @lc code=end

