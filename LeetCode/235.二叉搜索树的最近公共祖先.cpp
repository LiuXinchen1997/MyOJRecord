/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur_node = root;
        while (1) {
            if (p->val == cur_node->val || q->val == cur_node->val) { return cur_node; }
            else if (p->val > cur_node->val && q->val > cur_node->val) { cur_node = cur_node->right; }
            else if (p->val < cur_node->val && q->val < cur_node->val) { cur_node = cur_node->left; }
            else { return cur_node; }
        }

        return nullptr;
    }
};
// @lc code=end

