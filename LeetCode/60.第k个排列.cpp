/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 第k个排列
 */

// @lc code=start
class Solution {
public:
    void solve(string cur, int n, int k, vector<int> visited,
     int& rank, bool& finished, string& res, vector<int>& fs) {
        if (finished) { return; }
        if (cur.size() == n) {
            rank += 1;
            if (rank == k) {
                finished = true;
                res = cur;
            }
            return;
        }


        for (int i = 1; i <= n; i++) {
            if (visited[i]) { continue; }
            if (rank + fs[n - (cur+char(i+'0')).size()] < k) {
                rank += fs[n - (cur+char(i+'0')).size()];
                continue;
            }
            visited[i] = true;
            solve(cur+char(i+'0'), n, k, visited, rank, finished, res, fs);
            visited[i] = false;
        }
    }

    void generate_fs(vector<int>& fs) {
        fs[0] = 1;
        int res = 1;
        for (int i = 1; i <= 9; i++) {
            res *= i;
            fs[i] = res;
        }
    }

    string getPermutation(int n, int k) {
        vector<int> visited(n+1, 0);
        vector<int> fs(10, 0);
        generate_fs(fs);
        int rank = 0;
        bool finished = false;
        string res = "";
        solve("", n, k, visited, rank, finished, res, fs);

        return res;
    }
};
// @lc code=end

