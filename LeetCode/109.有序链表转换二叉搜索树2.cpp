/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* buildTree(vector<int>& arr, int l, int r) {
        if (l > r) { return NULL; }
        
        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = buildTree(arr, l, mid-1);
        root->right = buildTree(arr, mid+1, r);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) { return NULL; }

        vector<int> arr;
        ListNode* cur = head;
        while (cur) {
            arr.push_back(cur->val);
            cur = cur->next;
        }

        TreeNode* root = buildTree(arr, 0, arr.size()-1);
        return root;
    }
};
// @lc code=end

