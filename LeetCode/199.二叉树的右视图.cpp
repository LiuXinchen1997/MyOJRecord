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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) { return res; }
        
        map<int, int> depth2val;
        int max_depth = -1;

        queue<TreeNode*> node_q;
        queue<int> depth_q;
        node_q.push(root);
        depth_q.push(1);

        while (!node_q.empty()) {
            TreeNode* cur_node = node_q.front(); node_q.pop();
            int cur_depth = depth_q.front(); depth_q.pop();

            if (max_depth < cur_depth) { max_depth = cur_depth; }

            depth2val[cur_depth] = cur_node->val;
            
            if (cur_node->left) { 
                node_q.push(cur_node->left);
                depth_q.push(cur_depth+1); 
            }
            if (cur_node->right) { 
                node_q.push(cur_node->right);
                depth_q.push(cur_depth+1); 
            }
        }

        for (int i = 1; i <= max_depth; i++) {
            res.push_back(depth2val[i]);
        }

        return res;
    }
};
// @lc code=end

