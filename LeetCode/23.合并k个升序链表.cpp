/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) { return nullptr; }
        
        int n = lists.size();
        vector<ListNode*> cur_nodes(n, nullptr);
        for (int i = 0; i < n; i++) {
            cur_nodes[i] = lists[i];
        }
        
        ListNode* dummy_head = new ListNode();
        ListNode* res = nullptr;
        while (1) {
            ListNode* tmp_node = nullptr;
            int selected_i = -1;
            for (int i = 0; i < n; i++) {
                if (cur_nodes[i] == nullptr) { continue; }
                if (tmp_node == nullptr || tmp_node->val > cur_nodes[i]->val) {
                    tmp_node = cur_nodes[i];
                    selected_i = i;
                }
            }

            if (tmp_node == nullptr) { break; }

            cur_nodes[selected_i] = cur_nodes[selected_i]->next;
            if (res == nullptr) {
                res = tmp_node;
                dummy_head->next = res;
                res->next = nullptr;
            } else {
                res->next = tmp_node;
                res = res->next;
                res->next = nullptr;
            }
        }

        return dummy_head->next;
    }
};
// @lc code=end

