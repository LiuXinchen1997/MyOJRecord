/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) {
            return nullptr;
        }

        ListNode* quick_node = head;
        ListNode* slow_node = head;
        while (1) {
            slow_node = slow_node->next;
            if (quick_node->next && quick_node->next->next) {
                quick_node = quick_node->next->next;
            } else { return nullptr; }

            if (!quick_node || !slow_node) { return nullptr; }

            if (slow_node == quick_node) { break; }
        }

        ListNode* cur_node = head;
        while (1) {
            if (cur_node == slow_node) { return cur_node; }
            cur_node = cur_node->next;
            slow_node = slow_node->next;
        }
    }
};
// @lc code=end

