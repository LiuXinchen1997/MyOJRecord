/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    int pathSum(TreeNode* root, int sum) {
        queue<TreeNode*> q;
        if (root == nullptr) { return 0; }

        unordered_map<int, int> m;
        m[0] = 1;
        return solver(m, root, 0, sum);
    }

    int solver(unordered_map<int, int> m, TreeNode* node, int cur_sum, int sum)
    {
        if (node == nullptr) {
            return 0;
        }
        
        int ans = 0;
        cur_sum += node->val;
        if (m.count(cur_sum - sum) != 0) {
            ans += m[cur_sum-sum];
        }
        if (m.count(cur_sum) == 0) {
            m[cur_sum] = 1;
        } else {
            m[cur_sum] += 1;
        }

        ans += solver(m, node->left, cur_sum, sum);
        ans += solver(m, node->right, cur_sum, sum);

        m[cur_sum] -= 1;
        return ans;
    }
};
// @lc code=end

