/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        if (root == nullptr) { return 0; }
        queue<TreeNode*> que;
        que.push(root);
        int depth = 1;
        int count = 1;

        while (1) {
            int pre_count = count;
            count = 0;

            while (pre_count--) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left == nullptr && node->right == nullptr) { return depth; }
                if (node->left) { que.push(node->left); count += 1; }
                if (node->right) { que.push(node->right); count += 1; }
            }

            depth += 1;
        }
    }
};
// @lc code=end

