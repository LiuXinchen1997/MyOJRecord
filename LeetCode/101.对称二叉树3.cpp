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
    int get_depth(TreeNode* root) {
        if (root == nullptr) { return 0; }
        return max(get_depth(root->left), get_depth(root->right)) + 1;
    }

    bool check_sym(vector<TreeNode*>& nodes, int l, int r) {
        for (int i = l, j = r; i <= j; i++, j--) {
            if (nodes[i] == nullptr && nodes[j] == nullptr) { continue; }
            if (nodes[i] == nullptr && nodes[j] != nullptr) { return false; }
            if (nodes[i] != nullptr && nodes[j] == nullptr) { return false; }
            if (nodes[i]->val != nodes[j]->val) { return false; }
        }

        return true;
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) { return true; }
        int depth = get_depth(root);
        if (depth == 1) { return true; }

        vector<TreeNode*> nodes;
        nodes.emplace_back(root);
        
        int cur_id = 0;
        for (int i = 1; i <= depth; i++) {
            int end_id = cur_id + (1 << (i-1));
            
            if (!check_sym(nodes, cur_id, end_id-1)) {
                return false;
            }

            for (int j = cur_id; j < end_id; j++) {
                if (nodes[j] == nullptr) {
                    nodes.emplace_back(nullptr);
                    nodes.emplace_back(nullptr);
                } else {
                    nodes.emplace_back(nodes[j]->left);
                    nodes.emplace_back(nodes[j]->right);
                }
            }

            cur_id += (1 << (i-1));
        }

        return true;
    }
};
// @lc code=end

