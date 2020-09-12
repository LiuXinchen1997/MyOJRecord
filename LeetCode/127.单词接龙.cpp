/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
public:
    void update_state2word(vector<string>& wordList, map<string, vector<string>>& state2word) {
        for (string word : wordList) {
            for (int i = 0; i < word.size(); i++) {
                string state = word.substr(0, i) + string("*") + word.substr(i+1, string::npos);
                if (state2word.count(state) == 0) {
                    state2word[state] = vector<string>();
                }
                state2word[state].push_back(word);
            }
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, vector<string>> state2word;
        update_state2word(wordList, state2word);

        queue<string> qs;
        queue<int> qi;
        qs.push(beginWord);
        qi.push(1);

        map<string, bool> visited;
        for (string word : wordList) { visited[word] = false; }

        while (!qs.empty()) {
            string curWord = qs.front(); qs.pop();
            int curLen = qi.front(); qi.pop();
            if (curWord == endWord) { return curLen; }

            for (int i = 0; i < curWord.size(); i++) {
                string cur_state = curWord.substr(0, i) + string("*") + curWord.substr(i+1, string::npos);
                vector<string> candidateWordList = state2word[cur_state];
                for (string candidateWord : candidateWordList) {
                    if (candidateWord != curWord && !visited[candidateWord]) {
                        visited[candidateWord] = true;
                        qs.push(candidateWord);
                        qi.push(curLen + 1);
                    }
                }
            }
        }

        return 0;
    }
};
// @lc code=end
