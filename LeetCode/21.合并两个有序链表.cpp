/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy_head = new ListNode();
        ListNode* cur_node = dummy_head;
        ListNode* cur_node1 = l1;
        ListNode* cur_node2 = l2;

        while (cur_node1 && cur_node2) {
            if (cur_node1->val <= cur_node2->val) {
                cur_node->next = cur_node1;
                cur_node = cur_node->next;
                cur_node1 = cur_node1->next;
            } else {
                cur_node->next = cur_node2;
                cur_node = cur_node->next;
                cur_node2 = cur_node2->next;
            }
        }

        while (cur_node1) {
            cur_node->next = cur_node1;
            cur_node = cur_node->next;
            cur_node1 = cur_node1->next;
        }

        while (cur_node2) {
            cur_node->next = cur_node2;
            cur_node = cur_node->next;
            cur_node2 = cur_node2->next;
        }

        cur_node->next = nullptr;

        return dummy_head->next;
    }
};
// @lc code=end

