/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> visited;

    Node* cloneGraph(Node* node) {
        if (node == nullptr) { return node; }

        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        Node* clone_node = new Node(node->val);
        visited[node] = clone_node;
        for (Node* neighbor : node->neighbors) {
            clone_node->neighbors.emplace_back(cloneGraph(neighbor));
        }

        return clone_node;
    }
};
// @lc code=end

