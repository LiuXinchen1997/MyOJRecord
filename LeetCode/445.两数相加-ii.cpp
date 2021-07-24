/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        ListNode* dummy_head = new ListNode();
        int carry = 0;
        while (!s1.empty() || !s2.empty()) {
            int a = s1.empty() ? 0 : s1.top();
            int b = s2.empty() ? 0 : s2.top();
            if (!s1.empty()) { s1.pop(); }
            if (!s2.empty()) { s2.pop(); }

            int tmp = a + b + carry;
            carry = tmp / 10;
            ListNode* cur = new ListNode(tmp % 10);
            cur->next = dummy_head->next;
            dummy_head->next = cur;
        }

        if (carry) {
            ListNode* cur = new ListNode(1);
            cur->next = dummy_head->next;
            dummy_head->next =  cur;
        }

        return dummy_head->next;
    }
};
// @lc code=end

