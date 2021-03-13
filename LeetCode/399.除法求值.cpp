/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 */

// @lc code=start
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> str2id;
        int id = 0;
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            if (str2id.count(a) == 0) { str2id[a] = id++; }
            if (str2id.count(b) == 0) { str2id[b] = id++; }
        }

        vector<vector<double>> graph(id, vector<double>(id, -1.0));
        for (int i = 0; i < equations.size(); i++) {
            int va = str2id[equations[i][0]];
            int vb = str2id[equations[i][1]];
            graph[va][vb] = values[i];
            graph[vb][va] = 1.0 / values[i];
        }

        for (int k = 0; k < id; k++) {
            for (int i = 0; i < id; i++) {
                for (int j = 0; j < id; j++) {
                    if (graph[i][k] > 0 && graph[k][j] > 0) {
                        graph[i][j] = graph[i][k] * graph[k][j];
                    }
                }
            }
        }

        vector<double> res;
        for (auto& q : queries) {
            double result = -1.0;
            string sa = q[0];
            string sb = q[1];
            if (str2id.count(sa) == 0) { res.push_back(result); continue; }
            if (str2id.count(sb) == 0) { res.push_back(result); continue; }

            int va = str2id[sa];
            int vb = str2id[sb];
            if (graph[va][vb] > 0) {
                result = graph[va][vb];
            }
            res.push_back(result);
        }

        return res;
    }
};
// @lc code=end

