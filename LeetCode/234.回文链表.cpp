/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool cmp(ListNode* node, ListNode*& start_node) {
        if (node->next) {
            if (!cmp(node->next, start_node)) {
                return false;
            }
        }

        if (start_node->val != node->val) { return false; }
    }

    bool isPalindrome(ListNode* head) {
        cmp()
    }
};
// @lc code=end

