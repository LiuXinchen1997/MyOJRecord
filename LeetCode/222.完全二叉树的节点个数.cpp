/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes(TreeNode* root) {
        if (root == nullptr) { return 0; }
        int h = 0;
        TreeNode* tmp_node = root;
        while (tmp_node) {
            tmp_node = tmp_node->left;
            if (tmp_node) { h += 1; }
        }

        int res = 0;
        for (int i = 0; i < h; i++) {
            res += (1 << i);
        }

        int l = (1 << h);
        int r = (1 << (h+1)) - 1;
        
        while (l < r) {
            int mid = (r-l+1) / 2 + l;
            // int mid = (r + l) / 2;
            tmp_node = root;
            for (int i = h-1; i >= 0; i--) {
                if ((1<<i) & mid) {
                    tmp_node = tmp_node->right;
                } else {
                    tmp_node = tmp_node->left;
                }
            }

            if (tmp_node) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        return l;
    }
};
// @lc code=end

