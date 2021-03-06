/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int max_deep;

    void dfs(TreeNode* root, int depth) {
        if (root == nullptr) { return; }
        max_deep = max(max_deep, depth);

        if (root->left) {
            dfs(root->left, depth+1);
        }
        if (root->right) {
            dfs(root->right, depth+1);
        }
    }

    int maxDepth(TreeNode* root) {
        max_deep = 0;
        if (root == nullptr) { return max_deep; }
        dfs(root, 1);

        return max_deep;
    }
};
// @lc code=end

