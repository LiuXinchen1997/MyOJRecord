/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) { return false; }
        
        ListNode* quick_node = head;
        ListNode* slow_node = head;
        
        quick_node = head->next->next;
        slow_node = head->next;
        while (true) {
            if (quick_node == nullptr || slow_node == nullptr) { return false; }
            if (quick_node == slow_node) { return true; }

            slow_node = slow_node->next;
            if (quick_node->next && quick_node->next->next) {
                quick_node = quick_node->next->next;
            } else {
                return false;
            }
        }
    }
};
// @lc code=end

