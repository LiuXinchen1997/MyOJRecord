/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void solve(Node* left, Node* right, Node* father) {
        if (left) { left->next = right; }
        if (right && father->next) { right->next = father->next->left; }
        
        if (left) { solve(left->left, left->right, left); }
        if (right) { solve(right->left, right->right, right); }
    }

    Node* connect(Node* root) {
        if (root == nullptr) { return root; }
        solve(root->left, root->right, root);

        return root;
    }
};
// @lc code=end

