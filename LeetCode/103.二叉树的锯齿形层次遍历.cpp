/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) { return res; }

        stack<TreeNode*> s;
        stack<TreeNode*> s2;
        s.push(root);

        int cur_level = 0;
        while (true) {
            if (res.size() <= cur_level) { res.push_back(vector<int>()); }
            if (cur_level % 2 == 0) {
                if (s.empty()) { break; }
                while (!s.empty()) {
                    TreeNode* cur_node = s.top(); s.pop();
                    res[cur_level].push_back(cur_node->val);
                    if (cur_node->left) { s2.push(cur_node->left); }
                    if (cur_node->right) { s2.push(cur_node->right); }
                }
            } else {
                if (s2.empty()) { break; }
                while (!s2.empty()) {
                    TreeNode* cur_node = s2.top(); s2.pop();
                    res[cur_level].push_back(cur_node->val);
                    if (cur_node->right) { s.push(cur_node->right); }
                    if (cur_node->left) { s.push(cur_node->left); }
                }
            }

            cur_level++;
        }

        res.pop_back();
        return res;
    }
};
// @lc code=end
