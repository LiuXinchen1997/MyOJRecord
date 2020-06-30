/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
    vector<TreeNode*> solve(int start, int end) {
        vector<TreeNode*> res;
        if (start > end) {
            res.push_back(NULL);
            return res;
        }

        if (start == end) {
            TreeNode* node = new TreeNode(start);
            res.push_back(node);
            return res;
        }

        for (int i = start; i <= end; i++) {
            // node i ==> root node
            vector<TreeNode*> leftTrees = solve(start, i-1);
            vector<TreeNode*> rightTrees = solve(i+1, end);

            for (auto leftTree : leftTrees) {
                for (auto rightTree : rightTrees) {
                    TreeNode* root = new TreeNode(i, leftTree, rightTree);
                    res.push_back(root);
                }
            }
        }

        return res;
    }

    vector<TreeNode*> generateTrees(int n) {  
        vector<TreeNode*> res;
        if (0 == n) { return res; }

        res = solve(1, n);
        return res;
    }
};
// @lc code=end

