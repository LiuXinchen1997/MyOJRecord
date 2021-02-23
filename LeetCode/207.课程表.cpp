/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses <= 1) { return true; }
        vector<int> ind(numCourses, 0);
        vector<bool> visited(numCourses, false);

        vector<vector<int>> graph(numCourses, vector<int>());

        for (auto info : prerequisites) {
            // info[1] --> info[0]
            graph[info[1]].push_back(info[0]);
            ind[info[0]] += 1; 
        }

        while (1) {
            int cur = -1;
            for (int i = 0; i < numCourses; i++) {
                if (!visited[i] && ind[i] == 0) {
                    cur = i;
                    visited[i] = true;
                    for (auto id : graph[i]) { ind[id] -= 1; }
                    break;
                }
            }

            if (cur == -1) { break; }
        }

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) { return false; }
        }

        return true;
    }
};
// @lc code=end
