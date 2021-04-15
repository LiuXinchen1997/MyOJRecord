/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    int abs(int a) {
        return a < 0 ? -a : a;
    }

    int calc_depth(TreeNode* root, bool& balance)
    {
        if (root == nullptr) { return 0; }
        int left_depth = calc_depth(root->left, balance);
        int right_depth = calc_depth(root->right, balance);
        if (abs(left_depth-right_depth) > 1) { balance = false; }

        int cur_depth = max(left_depth, right_depth) + 1;
        return cur_depth;
    }

    bool isBalanced(TreeNode* root) {
        bool balance = true;
        calc_depth(root, balance);
        return balance;
    }
};
// @lc code=end

