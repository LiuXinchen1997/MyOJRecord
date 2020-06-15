/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
// dp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        if (0 == candidates.size()) { return res; }

        map<int, vector<vector<int> > > m;
        for (int i = 1; i <= target; i++) {
            set<vector<int> > res_tmp;

            for (int j = 0; j < candidates.size(); j++) {
                if (i - candidates[j] < 0) { continue; }
                if (i - candidates[j] == 0) {
                    res_tmp.insert(vector<int>(1, i));
                    continue;
                }

                int tmp_i = i - candidates[j]; // > 0
                vector<vector<int> > res_tmp_i = m[tmp_i];
                for (int k1 = 0; k1 < res_tmp_i.size(); k1++) {
                    vector<int> tmp_v = res_tmp_i[k1];
                    tmp_v.push_back(candidates[j]);
                    sort(tmp_v.begin(), tmp_v.end());
                    res_tmp.insert(tmp_v);
                }
            }

            vector<vector<int> > ress;
            for (set<vector<int> >::iterator it = res_tmp.begin(); it != res_tmp.end(); it++) {
                ress.push_back(*it);
            }
            m[i] = ress;
        }

        return m[target];
    }
};
// @lc code=end

