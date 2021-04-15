/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    void inorder(TreeNode* root, vector<int>& nums) {
        if (root == nullptr) { return; }

        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

    void find2pos(vector<int>& nums, int& x, int& y, int& count)
    {
        count = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i+1]) {
                count += 1;
                if (-1 == x) { x = nums[i]; }
                y = nums[i+1];
            }
        }
    }

    void recoverInorder(TreeNode* root, int x, int y)
    {
        if (root == nullptr) { return; }
        recoverInorder(root->left, x, y);
        if (root->val == x) {
            root->val = y;
        } else if (root->val == y) {
            root->val = x;
        }
        recoverInorder(root->right, x, y);
    }

    void recoverTree(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);

        int x = -1;
        int y = -1;
        int count = 0;
        find2pos(nums, x, y, count);
        recoverInorder(root, x, y);
    }
};
// @lc code=end

