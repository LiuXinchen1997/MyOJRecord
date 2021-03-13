/*
 * @lc app=leetcode.cn id=705 lang=cpp
 *
 * [705] 设计哈希集合
 */

// @lc code=start
struct Node {
    int val;
    Node* next;
    Node() {
        val = 0;
        next = nullptr;
    }
    Node(int val_) {
        val = val_;
        next = nullptr;
    }
};

class MyHashSet {
public:
    vector<Node*> container;
    /** Initialize your data structure here. */
    MyHashSet() {
        int base = 769;
        container = vector<Node*>(769, nullptr);
    }
    
    void add(int key) {
        if (contains(key)) { return; }
        int bucket = key % 769;
        Node* node = container[bucket];
        if (node == nullptr) {
            container[bucket] = new Node(key);
            return;
        }
        while (node->next) {
            node = node->next;
        }
        node->next = new Node(key);
    }
    
    void remove(int key) {
        int bucket = key % 769;
        Node* node = container[bucket];
        if (node == nullptr) { return; }
        Node* pre_node = nullptr;
        while (node) {
            if (node->val == key) {
                if (pre_node == nullptr) {
                    container[bucket] = node->next;
                } else {
                    pre_node->next = node->next;
                }
                delete node;
                break;
            }
            pre_node = node;
            node = node->next;
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int bucket = key % 769;
        Node* node = container[bucket];
        if (node == nullptr) { return false; }

        while (node) {
            if (node->val == key) { return true; }
            node = node->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end

