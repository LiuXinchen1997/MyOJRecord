/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) { return head; }
        if (head->next == NULL) { return head; }

        ListNode* pre = new ListNode();
        ListNode* tmp = pre;
        pre->next = head;
        ListNode* left = head;
        ListNode* right = head;

        while (left) {
            while (right->next && left->val == right->next->val) {
                right = right->next;
            }
            if (left == right) {
                pre = left;
                left = left->next;
                right = left;
            } else {
                right = right->next;
                left = right;
                if (pre->next == head) {
                    head = left;
                }
                pre->next = left;
            }
        }

        delete tmp;
        return head;
    }
};
// @lc code=end

