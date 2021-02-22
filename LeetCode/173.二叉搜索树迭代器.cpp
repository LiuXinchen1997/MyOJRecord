/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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
class BSTIterator {
public:
    vector<int> vals;
    int cur_idx;

    void morder(TreeNode* root) {
        if (root->left) { morder(root->left); }
        vals.push_back(root->val);
        if (root->right) { morder(root->right); }
    }

    BSTIterator(TreeNode* root) {
        morder(root);
        this->cur_idx = 0;
    }
    
    int next() {
        return vals[cur_idx++];
    }
    
    bool hasNext() {
        return this->cur_idx < vals.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

