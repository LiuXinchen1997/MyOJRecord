/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
struct MyNode {
    vector<MyNode*> childs;
    bool is_word;

    MyNode() {
        childs = vector<MyNode*>(26, nullptr);
        is_word = false;
    }
};

class Trie {
public:
    MyNode* root;

    /** Initialize your data structure here. */
    Trie() {
        root = new MyNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        MyNode* cur_node = root;
        for (char ch : word) {
            if (cur_node->childs[ch - 'a'] == nullptr) {
                cur_node->childs[ch - 'a'] = new MyNode();
            }
            cur_node = cur_node->childs[ch - 'a'];
        }
        cur_node->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        MyNode* cur_node = root;
        for (char ch : word) {
            if (cur_node->childs[ch - 'a'] == nullptr) {
                return false;
            }
            cur_node = cur_node->childs[ch - 'a'];
        }
        if (cur_node->is_word) { return true; }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        MyNode* cur_node = root;
        for (char ch : prefix) {
            if (cur_node->childs[ch - 'a'] == nullptr) {
                return false;
            }
            cur_node = cur_node->childs[ch - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

