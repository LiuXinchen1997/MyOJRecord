/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
public:
    int is_neighbor(string& word1, string& word2) {
        // 1: the same
        // 2: is_neighbor
        // 3: is_not_neighbor
        // asert: word1.size() == word2.size()
        bool has_diff_alpha = false;
        for (int i = 0; i < word1.size(); i++) {
            if (word1[i] != word2[i]) {
                if (!has_diff_alpha) { has_diff_alpha = true; }
                else { return 3; }
            }
        }

        if (has_diff_alpha) { return 2; }
        else { return 1; }
    }

    void dfs(string curWord, string& endWord, vector<string>& wordList, vector<bool>& is_used, int len, int& res) {
        if (curWord == endWord) {
            if (res == 0) { res = len; }
            else if (res > len) { res = len; }
            return;
        }
        for (int i = 0; i < wordList.size(); i++) {
            if (!is_used[i] && is_neighbor(curWord, wordList[i]) == 2) {
                is_used[i] = true;
                dfs(wordList[i], endWord, wordList, is_used, len + 1, res);
                is_used[i] = false;
            }
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<bool> is_used(wordList.size(), false);
        int res = 0;
        dfs(beginWord, endWord, wordList, is_used, 1, res);
        return res;
    }
};
// @lc code=end

