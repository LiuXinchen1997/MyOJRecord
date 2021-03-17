/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);

        while (!q.empty()) {
            TreeNode* cur1 = q.front(); q.pop();
            TreeNode* cur2 = q.front(); q.pop();

            if (!cur1 && !cur2) { continue; }
            if (!cur1 || !cur2) { return false; }
            if (cur1->val != cur2->val) { return false; }

            q.push(cur1->left);
            q.push(cur2->right);
            q.push(cur1->right);
            q.push(cur2->left);
        }

        return true;
    }
};
// @lc code=end

