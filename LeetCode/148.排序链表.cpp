/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode* sortList(ListNode* head) {
        return sortList(head, nullptr);
    }

    ListNode* sortList(ListNode* head, ListNode* tail) {
        if (head == nullptr) { return head; }
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }

        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != tail) {
            fast = fast->next;
            slow = slow->next;

            if (fast != tail) {
                fast = fast->next;
            }
        }

        ListNode* mid = slow;
        return merge(sortList(head, mid), sortList(mid, tail));
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummy_head = new ListNode(0);
        ListNode* temp = dummy_head;
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;

        while (temp1 && temp2) {
            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp = temp->next;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp = temp->next;
                temp2 = temp2->next;
            }
        }

        if (temp1) {
            temp->next = temp1;
        } else if (temp2) {
            temp->next = temp2;
        }

        return dummy_head->next;
    }
};
// @lc code=end

