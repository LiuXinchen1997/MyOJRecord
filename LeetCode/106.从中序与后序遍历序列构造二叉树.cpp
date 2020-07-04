/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildSubTree(vector<int>& inorder, vector<int>& postorder, 
    int inorder_left, int inorder_right, int postorder_left, int postorder_right) {
        if (inorder_left > inorder_right) { return NULL; }

        TreeNode* root = new TreeNode(postorder[postorder_right]);
        int inorder_mid = index[root->val];
        int left_subtree_num = inorder_mid - inorder_left;
        root->left = buildSubTree(inorder, postorder, inorder_left, inorder_mid-1, postorder_left, postorder_left+left_subtree_num-1);
        root->right = buildSubTree(inorder, postorder, inorder_mid+1, inorder_right, postorder_left+left_subtree_num, postorder_right-1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0) { return NULL; }

        for (int i = 0; i < inorder.size(); i++) {
            index[inorder[i]] = i;
        }
        TreeNode* root = buildSubTree(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
        return root;
    }
};
// @lc code=end

