/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) { return head; }
        
        ListNode* cur = head;
        int cur_id = 1;

        ListNode* con = NULL;
        while (true) {
            if (cur_id == m - 1) { con = cur; }
            if (cur_id == m) { break; }
            cur_id++;
            cur = cur->next;
        }

        ListNode* pre = NULL;
        ListNode* tail = new ListNode(0);
        tail->next = cur;
        while (cur) {
            if (cur_id == n + 1) { break; }
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
            cur_id++;
        }

        tail->next->next = cur;
        if (con) { con->next = pre; }
        else { head = pre; }
        
        delete tail;
        return head;
    }
};
// @lc code=end

