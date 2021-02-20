/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> visited;

    Node* copyRandomList(Node* head) {
        if (head == nullptr) { return nullptr; }

        if (visited.find(head) != visited.end()) { return visited[head]; }

        Node* clone_node = new Node(head->val);
        visited[head] = clone_node;

        clone_node->next = copyRandomList(head->next);
        clone_node->random = copyRandomList(head->random);

        return clone_node;  
    }
};
// @lc code=end

