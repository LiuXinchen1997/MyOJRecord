/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    int sum;

    void dfs(TreeNode* root) {
        if (root->right) {
            dfs(root->right);
        }

        sum += root->val;
        root->val = sum;

        if (root->left) {
            dfs(root->left);
        }
    }

    TreeNode* convertBST(TreeNode* root) {
       if (root == nullptr) {
           return nullptr;
       }

        sum = 0;
        dfs(root);
        return root;
    }
};
// @lc code=end

