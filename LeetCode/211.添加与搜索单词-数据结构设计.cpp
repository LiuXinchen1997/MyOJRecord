/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start
struct MyNode {
    vector<MyNode*> childs;
    bool is_word;

    MyNode () {
        childs = vector<MyNode*>(26, nullptr);
        is_word = false;
    }
};

class WordDictionary {
public:
    MyNode* root;

    /** Initialize your data structure here. */
    WordDictionary() {
        root = new MyNode;
    }
    
    void addWord(string word) {
        MyNode* cur_node = root;
        for (auto ch : word) {
            if (cur_node->childs[ch - 'a'] == nullptr) {
                cur_node->childs[ch - 'a'] = new MyNode();
            }
            cur_node = cur_node->childs[ch - 'a'];
        }

        cur_node->is_word = true;
    }
    
    void dfs (MyNode* cur_node, string& word, int id, bool& res) {
        if (cur_node == nullptr) { return; }
        int len = word.size();
        if (id >= len) { return; }
        
        char ch = word[id];
        if (ch >= 'a' && ch <= 'z') {
            MyNode* tmp_node = cur_node->childs[ch - 'a'];
            if (tmp_node == nullptr) { return; }
            cur_node = tmp_node;
            if (id == len - 1 && cur_node->is_word) {
                res = true;
                return;
            }
            dfs(cur_node, word, id+1, res);
        } else if ('.' == ch) {
            for (int i = 0; i < 26; i++) {
                if (cur_node->childs[i]) {
                    if (id == len - 1 && cur_node->childs[i]->is_word) {
                        res = true;
                        return;
                    }
                    dfs(cur_node->childs[i], word, id+1, res);
                }
            }
        }
    }

    bool search(string word) {
        bool res = false;
        dfs(root, word, 0, res);
        return res;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

