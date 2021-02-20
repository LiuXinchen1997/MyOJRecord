/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
struct Node {
    int key, val;
    Node* prev;
    Node* succ;
    
    Node() : key(-1), val(-1), prev(nullptr), succ(nullptr) {}
    Node(int _key, int _val) : key(_key), val(_val), prev(nullptr), succ(nullptr) {}
    Node(int _key, int _val, Node* _prev, Node* _succ) : key(_key), val(_val), prev(_prev), succ(_succ) {}
};

class LRUCache {
public:
    Node* head;
    Node* tail;
    int size;
    int capacity;
    map<int, Node*> cache;

    LRUCache(int capacity) {
        this->size = 0;
        this->capacity = capacity;

        this->head = new Node();
        this->tail = new Node();
        this->head->prev = nullptr;
        this->head->succ = tail;
        this->tail->prev = head;
        this->tail->succ = nullptr;
    }
    
    int get(int key) {
        if (cache.count(key) == 0) {
            return -1;
        }

        Node* cur_node = cache[key];
        cur_node->prev->succ = cur_node->succ;
        cur_node->succ->prev = cur_node->prev;
        
        cur_node->prev = head;
        cur_node->succ = head->succ;
        head->succ->prev = cur_node;
        head->succ = cur_node;

        return cur_node->val;
    }

    void put(int key, int value) {
        if (cache.count(key) != 0) {
            cache[key]->val = value;
            move_to_head(cache[key]);
            return;
        }

        size++;
        if (size > capacity) {
            Node* removed_node = tail->prev;
            remove_node(removed_node);

            cache.erase(removed_node->key);
            delete removed_node;
            size--;
        }

        Node* node = new Node(key, value);
        node->succ = head->succ;
        node->prev = head;
        head->succ->prev = node;
        head->succ = node;
        cache[key] = node;
    }

    Node* remove_node(Node* node) {
        node->prev->succ = node->succ;
        node->succ->prev = node->prev;
        return node;
    }

    void add_to_head(Node* node) {
        node->prev = head;
        node->succ = head->succ;
        head->succ->prev = node;
        head->succ = node;
    }

    void move_to_head(Node* node) {
        remove_node(node);
        add_to_head(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

