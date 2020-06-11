/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* cur = head;
        vector<ListNode*> v;
        while (cur) {
            len += 1;
            v.push_back(cur);
            cur = cur->next;
        }

        if (1 == len) { delete v[0]; return NULL; }
        if (1 == n) {
            delete v[len-1];
            v[len-2]->next = NULL;
            return v[0];
        }
        if (len == n) { delete v[0]; return v[1]; }

        v[len-n-1]->next = v[len-n]->next;
        delete v[len-n];
        return v[0];
    }
};
// @lc code=end

