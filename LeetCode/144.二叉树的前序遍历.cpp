/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        
        stack<TreeNode*> s;
        TreeNode* cur_node = root;
        while (!s.empty() || cur_node) {
            while (cur_node) {
                res.emplace_back(cur_node->val);
                s.push(cur_node);
                cur_node = cur_node->left;
            }
            
            cur_node = s.top(); s.pop();
            cur_node = cur_node->right;
        }

        return res;
    }
};
// @lc code=end

