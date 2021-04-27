/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy_node = new ListNode();
        dummy_node->next = head;

        ListNode* pre_node = nullptr;
        while (head) {
            if (pre_node) {
                if (pre_node->val == head->val) {
                    pre_node->next = head->next;
                } else {
                    pre_node = head;
                }
            } else {
                pre_node = head;
            }
            head = head->next;
        }

        return dummy_node->next;
    }
};
// @lc code=end

