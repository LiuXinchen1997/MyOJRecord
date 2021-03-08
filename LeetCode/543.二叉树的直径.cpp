/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
   int max_depth = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return max_depth;
    }

    int depth(TreeNode* root) {
        if (root == nullptr) { return 0; }

        int left_depth = depth(root->left);
        int right_depth = depth(root->right);
        max_depth = max(max_depth, left_depth + right_depth);
        return max(left_depth, right_depth) + 1;
    }
};
// @lc code=end

