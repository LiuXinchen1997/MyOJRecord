/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
private:
    unordered_map<int, int> index;

public:
    TreeNode* buildSubTree(vector<int>& preorder, vector<int>& inorder, 
    int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        if (inorder_left > inorder_right) { return NULL; }
        TreeNode* root = new TreeNode(preorder[preorder_left]);

        int inorder_mid = index[preorder[preorder_left]];

        int left_tree_nodes_num = inorder_mid - inorder_left;
        int right_tree_nodes_num = inorder_right - inorder_mid;
        root->left = buildSubTree(preorder, inorder, preorder_left+1, preorder_left+left_tree_nodes_num, inorder_left, inorder_mid-1);
        root->right = buildSubTree(preorder, inorder, preorder_left+left_tree_nodes_num+1,  preorder_left+left_tree_nodes_num+1+right_tree_nodes_num, inorder_mid+1, inorder_right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) { return NULL; }

        for (int i = 0; i < inorder.size(); i++) {
            index[inorder[i]] = i;
        }
        TreeNode* root = buildSubTree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
        return root;
    }
};
// @lc code=end
