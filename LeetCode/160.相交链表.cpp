/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    int gen_len(ListNode* head) {
        int len = 0;
        while (head) {
            len += 1;
            head = head->next;
        }

        return len;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lena = gen_len(headA);
        int lenb = gen_len(headB);

        if (lenb > lena) {
            for (int i = 0; i < lenb - lena; i++) {
                headB = headB->next;
            }
        } else if (lenb < lena) {
            for (int i = 0; i < lena - lenb; i++) {
                headA = headA->next;
            }
        }

        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};
// @lc code=end

