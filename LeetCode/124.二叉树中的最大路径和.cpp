/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int max_sum = -20000;

    int postorder(TreeNode* root) {
        if (root == nullptr) { return 0; }

        int left_val = max(postorder(root->left), 0);
        int right_val = max(postorder(root->right), 0);
        int cur_val = root->val + left_val + right_val;
        max_sum = max(max_sum, cur_val);
        return root->val + max(left_val, right_val);
    }

    int maxPathSum(TreeNode* root) {
        postorder(root);
        return max_sum;
    }
};
// @lc code=end

