/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

// @lc code=start
class Solution {
public:
    vector<int> f;
    vector<int> rankk;

    int find(int i)
    {
        if (i != f[i]) {
            f[i] = find(f[i]);
        }

        return f[i];
    }

    void union_set(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (rankk[x] < rankk[y]) {
            f[x] = y;
        } else {
            f[y] = x;
            if (rankk[x] == rankk[y]) {
                rankk[x] += 1;
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        f = vector<int>(n, 0);
        rankk = vector<int>(n, 1);
        for (int i = 0; i < n; i++) {
            f[i] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    union_set(i, j);
                }
            }
        }

        set<int> s;
        for (int i = 0; i < n; i++) {
            s.insert(find(i));
        }
        return s.size();
    }
};
// @lc code=end

