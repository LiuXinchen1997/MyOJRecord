/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        if (!head) { return NULL; }

        ListNode* before_head = new ListNode(0);
        ListNode* after_head = new ListNode(0);
        ListNode* before = before_head;
        ListNode* after = after_head;

        ListNode* cur = head;
        while (cur) {
            if (cur->val >= x) {
                after->next = cur;
                after = after->next;
            } else {
                before->next = cur;
                before = before->next;
            }

            cur = cur->next;
        }

        before->next = after_head->next;
        after->next = NULL;

        return before_head->next;
    }
};
// @lc code=end

