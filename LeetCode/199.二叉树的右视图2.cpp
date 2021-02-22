/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    void bianli(TreeNode* root, int depth, vector<int>& res) {
        if (root == nullptr) { return; }
        if (depth > res.size()) { res.emplace_back(root->val); }

        bianli(root->right, depth+1, res);
        bianli(root->left, depth+1, res);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) { return res; }

        bianli(root, 1, res);
        return res;
    }
};
// @lc code=end

