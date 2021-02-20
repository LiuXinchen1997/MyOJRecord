/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) { return res; }

        stack<TreeNode*> s;
        TreeNode* cur_node = root;
        TreeNode* prev = nullptr;
        
        while (!s.empty() || cur_node) {
            while (cur_node) {
                s.push(cur_node);
                cur_node = cur_node->left;
            }

            cur_node = s.top(); s.pop();

            if (cur_node->right == nullptr || cur_node->right == prev) {
                res.emplace_back(cur_node->val);
                prev = cur_node;
                cur_node = nullptr;
            } else {
                s.push(cur_node);
                cur_node = cur_node->right;
            }
        }

        return res;
    }
};
// @lc code=end

