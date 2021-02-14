/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
public:
    int num_node = 0;
    map<string, int> word2id;
    vector<vector<int> > graph;

    void add_word(string& word) {
        if (word2id.count(word) == 0) {
            word2id[word] = num_node++;
            graph.emplace_back();
        }
    }

    void add_edge(string& word) {
        if (word2id.count(word) != 0) {
            return;
        }

        add_word(word);
        int id1 = word2id[word];
        for (int i = 0; i < word.size(); i++) {
            string state = word.substr(0, i) + '*' + word.substr(i+1, string::npos);
            add_word(state);
            int id2 = word2id[state];
            graph[id1].push_back(id2);
            graph[id2].push_back(id1);
        }
    }

    void build_graph(string& beginWord, vector<string>& wordList) {
        for (string word : wordList) { add_edge(word); }
        add_edge(beginWord);
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        build_graph(beginWord, wordList);
        if (word2id.count(endWord) == 0) { return 0; }
        
        int begin_id = word2id[beginWord];
        int end_id = word2id[endWord];

        queue<int> q;
        queue<int> dists;
        vector<bool> visited(num_node, false);
        q.push(begin_id);
        dists.push(0);
        visited[begin_id] = true;
        while (true) {
            int cur_id = q.front(); q.pop();
            int cur_dist = dists.front(); dists.pop();

            for (int id : graph[cur_id]) {
                if (id == end_id) { return (cur_dist + 1) / 2 + 1; }
                if (!visited[id]) {
                    q.push(id);
                    dists.push(cur_dist + 1);
                    visited[id] = true;
                }
            }

            if (q.empty()) { break; }
        }

        return 0;
    }
};
// @lc code=end
