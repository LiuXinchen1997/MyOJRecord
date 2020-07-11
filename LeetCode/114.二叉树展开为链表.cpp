/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    void flatten(TreeNode* root) {
        while (root) {
            if (root->left == nullptr) { root = root->right; continue; }

            TreeNode* leftTree = root->left;
            TreeNode* rightTree = root->right;
            root->left = nullptr;
            root->right = leftTree;

            TreeNode* tmp = leftTree;
            while (tmp->right) { tmp = tmp->right; }
            tmp->right = rightTree;

            root = root->right;
        }
    }
};
// @lc code=end

