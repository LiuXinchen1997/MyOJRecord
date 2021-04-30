/*
 * @lc app=leetcode.cn id=815 lang=cpp
 *
 * [815] 公交路线
 */

// @lc code=start
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) { return 0; }
        for (int i = 0; i < routes.size(); i++) {
            sort(routes[i].begin(), routes[i].end());
        }

        int n = routes.size();
        unordered_set<int> source_bus;
        unordered_set<int> target_bus;
        for (int i = 0; i < n; i++) {
            if (binary_find(routes[i], source) != -1) { source_bus.insert(i); }
        }
        for (int i = 0; i < n; i++) {
            if (binary_find(routes[i], target) != -1) { 
                if (source_bus.count(i)) { return 1; }
                target_bus.insert(i);
            }
        }

        vector<vector<int>> graph(n, vector<int>());
        for (int i = 0; i < n; i += 1) {
            for (int j = i+1; j < n; j += 1) {
                if (interact(routes[i], routes[j])) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        int cur = 1;
        queue<int> que;
        vector<int> visited(n, false);
        for (auto bus : source_bus) {
            if (target_bus.count(bus)) { return cur; }
            que.push(bus);
            visited[bus] = true;
        }
        while (!que.empty()) {
            int cur_len = que.size();

            cur += 1;
            while (cur_len--) {
                int tmp = que.front(); que.pop();
                for (int tmp_id : graph[tmp]) {
                    if (visited[tmp_id]) { continue; }
                    if (target_bus.count(tmp_id)) { return cur; }
                    que.push(tmp_id);
                    visited[tmp_id] = true;
                }
            }
        }

        return -1;
    }

    int binary_find(vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] == target) { return mid; }
            else if (arr[mid] < target) { left = mid + 1; }
            else { right = mid - 1; }
        }

        return -1;
    }

    bool interact(vector<int>& arr1, vector<int>& arr2) {
        int id1 = 0, id2 = 0;
        while (id1 < arr1.size() && id2 < arr2.size()) {
            if (arr1[id1] == arr2[id2]) { return true; }
            else if (arr1[id1] < arr2[id2]) { id1 += 1; }
            else { id2 += 1; }
        }
        return false;
    }
};
// @lc code=end

