/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

// @lc code=start
class Solution {
public:
    int find(vector<int>& f, int i) {
        if (i != f[i]) {
            f[i] = find(f, f[i]);
        }
        return f[i];
    }

    void union_set(vector<int>& f, vector<int>& rankk, int x, int y) {
        x = find(f, x);
        y = find(f, y);
        if (rankk[x] < rankk[y]) {
            f[x] = y;
        } else {
            f[y] = x;
            if (rankk[x] == rankk[y]) {
                rankk[x] += 1;
            }
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> f(n+1, 0);
        vector<int> rankk(n+1, 1);
        for (int i = 1; i <= n; i++) {
            f[i] = i;
        }

        for (auto edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            if (find(f, node1) == find(f, node2)) { return edge; }
            union_set(f, rankk, node1, node2);
        }

        return edges[0];
    }
};
// @lc code=end

