/*
 * @lc app=leetcode.cn id=706 lang=cpp
 *
 * [706] 设计哈希映射
 */

// @lc code=start
struct Node {
    int key;
    int val;
    Node* next;

    Node() {
        key = -1;
        val = -1;
        next = nullptr;
    }

    Node(int key_, int value_) {
        key = key_;
        val = value_;
        next = nullptr;
    }
};

class MyHashMap {
public:
    const static int num_buckets = 769;
    vector<Node*> buckets;
    /** Initialize your data structure here. */
    MyHashMap() {
        buckets = vector<Node*>(num_buckets, new Node());
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int bid = key % num_buckets;
        Node* cur_node = buckets[bid];
        while (cur_node->next) {
            cur_node = cur_node->next;
            if (cur_node->key == key) {
                cur_node->val = value;
                return;
            }
        }
        cur_node->next = new Node(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int bid = key % num_buckets;
        Node* cur_node = buckets[bid];
        while (cur_node->next) {
            cur_node = cur_node->next;
            if (cur_node->key == key) {
                return cur_node->val;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int bid = key % num_buckets;
        Node* cur_node = buckets[bid];
        while (cur_node->next) {
            if (cur_node->next->key == key) {
                Node* tmp_node = cur_node->next;
                cur_node->next = tmp_node->next;
                delete tmp_node;
                return;
            }
            cur_node = cur_node->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end

