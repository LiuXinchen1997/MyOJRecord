/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        if (numCourses == 0) { return res; }
        if (numCourses == 1) {
            res.push_back(0);
            return res;
        }

        vector<bool> visited(numCourses, false);
        vector<int> ind(numCourses, 0);
        vector<vector<int>> graph(numCourses, vector<int>());
        for (auto info : prerequisites) {
            // info[1]-->info[0]
            graph[info[1]].push_back(info[0]);
            ind[info[0]] += 1;
        }
        
        while (1) {
            int tmp = -1;
            for (int i = 0; i < numCourses; i++) {
                if (!visited[i] && ind[i] == 0) {
                    tmp = i;
                    dfs(i, graph, ind, visited, res);
                }
            }
            if (-1 == tmp) { break; }
        }

        if (res.size() == numCourses) { return res; }
        else { return vector<int>(); }
    }

    void dfs(int id, vector<vector<int>>& graph, vector<int>& ind, vector<bool>& visited, vector<int>& res) {
        res.push_back(id);
        visited[id] = true;
        for (auto nei : graph[id]) {
            ind[nei] -= 1;
            if (ind[nei] == 0) { dfs(nei, graph, ind, visited, res); }
        }
    }
};
// @lc code=end

