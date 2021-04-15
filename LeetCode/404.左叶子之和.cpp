/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    void inorder(TreeNode* root, int& sum, bool is_left)
    {
        if (root == nullptr) { return; }
        if (is_left && root->left == nullptr && root->right == nullptr) {
            sum += root->val;
        }

        if (root->left) { inorder(root->left, sum, true); }
        if (root->right) { inorder(root->right, sum, false); }
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        inorder(root, sum, false);
        return sum;
    }
};
// @lc code=end

