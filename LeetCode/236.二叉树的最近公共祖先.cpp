/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
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
    unordered_map<TreeNode*, TreeNode*> f;
    unordered_map<TreeNode*, bool> vis;
    void inorder(TreeNode* root) {
        if (root == nullptr) { return; }
        if (root->left) {
            f[root->left] = root;
        }
        if (root->right) {
            f[root->right] = root;
        }
        
        inorder(root->left);
        inorder(root->right);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        inorder(root);
        
        TreeNode* cur_p = p;
        TreeNode* cur_q = q;
        f[root] = nullptr;
         
        while (cur_p) {
            vis[cur_p] = true;
            cur_p = f[cur_p];
        }

        while (cur_q) {
            if (vis[cur_q]) { return cur_q; }
            cur_q = f[cur_q];
        }

        return nullptr;
    }
};
// @lc code=end

