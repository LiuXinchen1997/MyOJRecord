/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    int res = -1;

    void inorder(TreeNode* root, int& id, int k) {
        if (root == nullptr) { return; }
        if (id > k) { return; }

        inorder(root->left, id, k);
        
        if (id == k) { res = root->val; id += 1; return; }
        id += 1;

        inorder(root->right, id, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        int id = 1;
        inorder(root, id, k);
        return res;
    }
};
// @lc code=end

