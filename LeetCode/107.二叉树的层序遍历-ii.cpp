/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (nullptr == root) {
            return ans;
        }

        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int level_num = que.size();
            vector<int> cur_vec;
            for (int i = 0; i < level_num; i++) {
                TreeNode* cur_node = que.front();
                que.pop();
                cur_vec.push_back(cur_node->val);
                if (cur_node->left) {
                    que.push(cur_node->left);
                }
                if (cur_node->right) {
                    que.push(cur_node->right);
                }
            }
            ans.emplace_back(cur_vec);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

