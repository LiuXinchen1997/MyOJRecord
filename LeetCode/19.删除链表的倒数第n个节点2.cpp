/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* cur = head;
        while (cur) {
            len += 1;
            cur = cur->next;
        }

        if (1 == len) { return NULL; }
        if (n == len) {
            ListNode* cur = head->next;
            delete head;
            head = cur;
            return head;
        }

        cur = head;
        for (int i = 0; i < len - n - 1; i++) { cur = cur->next; }

        ListNode* del = cur->next;
        if (del) {
            cur->next = del->next;
        }
        delete del;

        return head;
    }
};
// @lc code=end

