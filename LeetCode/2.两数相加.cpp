/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = NULL;
        ListNode* res_node;
        ListNode* l1_node = l1;
        ListNode* l2_node = l2;
        int carry = 0;
        while (l1_node && l2_node) {
            int tmp = l1_node->val + l2_node->val + carry;
            
            if (!res) {
                res = new ListNode(tmp % 10);
                res_node = res;
            } else {
                res_node->next = new ListNode(tmp % 10);
                res_node = res_node->next;
            }

            carry = tmp / 10;
            l1_node = l1_node->next;
            l2_node = l2_node->next;
        }

        while (l1_node) {
            int tmp = l1_node->val + carry;
            res_node->next = new ListNode(tmp % 10);
            res_node = res_node->next;
            carry = tmp / 10;
            l1_node = l1_node->next;
        }

        while (l2_node) {
            int tmp = l2_node->val + carry;
            res_node->next = new ListNode(tmp % 10);
            res_node = res_node->next;
            carry = tmp / 10;
            l2_node = l2_node->next;
        }

        if (carry) {
            res_node->next = new ListNode(carry);
            res_node = res_node->next;
        }

        return res;
    }
};
// @lc code=end

