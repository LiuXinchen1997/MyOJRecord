/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
public:
    void check(bool& res, long long& min_val, long long& max_val,  TreeNode* cur) {
        if (!res) { return; }
        if (!cur) { return; }

        long long left_max = LONG_MIN;
        long long left_min = LONG_MAX;
        long long right_max = LONG_MIN;
        long long right_min = LONG_MAX;
        
        check(res, left_min, left_max, cur->left);
        if (!res) { return; }
        
        check(res, right_min, right_max, cur->right);
        if (!res)  { return; }
        
        if (cur->val <= left_max || cur->val >= right_min) {
            res = false; return;
        }

        min_val = cur->val;
        if (left_min != LONG_MAX && left_min < min_val) { min_val = left_min; }
        if (right_min != LONG_MAX && right_min < min_val) { min_val = right_min; }

        max_val = cur->val;
        if (left_max != LONG_MIN && left_max > max_val) { max_val = left_max; }
        if (right_max != LONG_MIN && right_max > max_val) { max_val = right_max; }
    }

    bool isValidBST(TreeNode* root) {
        if (!root) { return true; }
        bool res = true;
        long long min_val = LONG_MAX;
        long long max_val = LONG_MIN;
        check(res, min_val, max_val, root);

        return res;
    }
};
// @lc code=end

