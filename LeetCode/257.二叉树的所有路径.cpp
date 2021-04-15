/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    void bianli(TreeNode* root, string cur_str, vector<string>& res) {
        if (root->left == nullptr && root->right == nullptr) {
            res.push_back(cur_str);
        }
        
        if (root->left) {
            string tmp_str = cur_str;
            tmp_str += "->";
            tmp_str += to_string(root->left->val);
            bianli(root->left, tmp_str, res); 
        }
        if (root->right) {
            string tmp_str = cur_str;
            tmp_str += "->";
            tmp_str += to_string(root->right->val);
            bianli(root->right, tmp_str, res);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        bianli(root, to_string(root->val), res);
        return res;
    }
};
// @lc code=end

