/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    int get_len(ListNode* head) {
        int len = 0;
        while (head) {
            len += 1;
            head = head->next;
        }

        return len;
    }

    void reverseKNodes(ListNode*& head, int k, ListNode*& group_head, ListNode*& group_tail) {
        ListNode* prev = nullptr;
        group_head = nullptr;
        group_tail = head;
        while (k--) {
            ListNode* tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        group_head = prev;
        group_tail->next = head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) { return head; }
        int len = get_len(head);
        int times = len / k;
        
        ListNode* group_head = nullptr;
        ListNode* group_tail = nullptr;
        ListNode* prev_group_tail = nullptr;
        ListNode* list_head = nullptr;
        for (int i = times; i > 0; i--) {
            reverseKNodes(head, k, group_head, group_tail);
            if (i == times) { list_head = group_head; }
            if (prev_group_tail) {
                prev_group_tail->next = group_head;
            }
            prev_group_tail = group_tail;
        }

        return list_head;
    }
};
// @lc code=end

