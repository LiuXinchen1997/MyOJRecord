/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
// bfs
struct Obj {
    vector<int> v;
    int id;
    int sum;
    Obj(const vector<int>& v_, int id_, int sum_) {
        v = v_;
        id = id_;
        sum = sum_;
    }

    Obj(const Obj& obj) {
        v = obj.v;
        id = obj.id;
        sum = obj.sum;
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        if (0 == candidates.size()) { return res; }

        queue<Obj> q;
        for (int i = 0; i < candidates.size(); i++) {
            if (candidates[i] > target) { continue; }
            q.push(Obj(vector<int>(1, candidates[i]), i, candidates[i]));
        }

        while (!q.empty()) {
            Obj obj = q.front(); q.pop();
            if (obj.sum == target) {
                res.push_back(obj.v); continue;
            } else if (obj.sum > target) { continue; }

            for (int i = obj.id; i < candidates.size(); i++) {
                if (obj.sum + candidates[i] <= target) {
                    Obj tmp = obj;
                    tmp.v.push_back(candidates[i]);
                    tmp.id = i;
                    tmp.sum += candidates[i];
                    q.push(tmp);
                }
            }
        }

        return res;
    }
};
// @lc code=end

