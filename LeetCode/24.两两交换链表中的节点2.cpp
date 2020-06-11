/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
 // 递归
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !(head->next)) { return head; }

        // 只考虑当前节点head和head->next节点的置换
        ListNode* next = head->next;
        
        next->next = swapPairs(next->next);
        
        head->next = next->next;
        next->next = head;

        return next;
    }
};
// @lc code=end

