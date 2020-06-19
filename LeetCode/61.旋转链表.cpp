/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) { return head; }
        if (0 == k) { return head; }
        
        ListNode* cur = head;
        int len = 1;
        while (cur->next) { len += 1; cur = cur->next; }
        if (1 == len) { return head; }
        k = k % len;
        cur->next = head;

        ListNode* pre = head;
        head = head->next;
        for (int i = 1; i < (len - k); i++) {
            head = head->next;
            pre = pre->next;
        }
        pre->next = NULL;

        return head;
    }
};
// @lc code=end

