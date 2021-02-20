/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr) { return nullptr; }

        ListNode* dummy_head = new ListNode(0);
        dummy_head->next = head;
        ListNode* last_sorted = head;
        ListNode* cur = head->next;

        while (cur) {
            if (last_sorted->val <= cur->val) {
                last_sorted = cur;
                cur = cur->next;
                continue;
            }

            ListNode* prev = dummy_head;
            while (prev->next->val < cur->val) {
                prev = prev->next;
            }
            
            last_sorted->next = cur->next;
            cur->next = prev->next;
            prev->next = cur;

            cur = last_sorted->next;
        }

        return dummy_head->next;
    }
};
// @lc code=end

