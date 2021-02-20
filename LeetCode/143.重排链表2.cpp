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
    void reorderList(ListNode* head) {
        if (head == nullptr) { return; }

        unordered_map<int, ListNode*> id2node;

        int cur_id = 0;
        ListNode* cur_node = head;
        while (1) {
            id2node[cur_id] = cur_node;

            cur_node = cur_node->next;
            if (cur_node == nullptr) { break; }
            cur_id += 1;
        }
        
        ListNode* tmp = nullptr;
        for (int i = 0, j = cur_id; i <= j; i++, j--) {
            if (tmp) { tmp->next = id2node[i]; }
            id2node[i]->next = id2node[j];
            id2node[j]->next = nullptr;
            tmp = id2node[j];
        }
    }
};
// @lc code=end

