/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    ListNode* find_middle_node(ListNode* head) {
        ListNode* slow = head;
        ListNode* quick = head;
        while (quick->next && quick->next->next) {
            quick = quick->next->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode* reverse_list(ListNode* head) {
        ListNode* pre_node = nullptr;
        ListNode* cur_node = head;
        while (cur_node) {
            ListNode* tmp = cur_node->next;
            cur_node->next = pre_node;
            pre_node = cur_node;
            cur_node = tmp;
        }

        return pre_node;
    }

    ListNode* merge_two_list(ListNode* head1, ListNode* head2) {
        ListNode* node1 = head1;
        ListNode* node2 = head2;
        
        while (node1 && node2) {
            ListNode* succ1 = node1->next;
            ListNode* succ2 = node2->next;

            node1->next = node2;
            node2->next = succ1;

            node1 = succ1;
            node2 = succ2;
        }

        return head1;
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) { return; }

        // 1. 找中点
        ListNode* mid_node = find_middle_node(head);

        ListNode* start_node1 = head;
        ListNode* start_node2 = mid_node->next;
        mid_node->next = nullptr;

        // 2. 链表倒置
        start_node2 = reverse_list(start_node2);

        // 3. 链表合并
        merge_two_list(start_node1, start_node2);
    }
};
// @lc code=end

