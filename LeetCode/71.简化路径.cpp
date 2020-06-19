/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        if (path.size() == 0) {
            return "/";
        }

        int start_id = path.find("/");
        int end_id = path.find("/", start_id + 1);
        vector<string> dirs;
        while (true) {
            if (start_id != string::npos && end_id != string::npos) {
                string dir = path.substr(start_id+1, end_id-start_id-1);
                if (dir == "..") {
                    if (dirs.size() > 0) { dirs.pop_back(); }
                } else if (dir != "" && dir != ".") { dirs.push_back(dir); }
                start_id = end_id;
                end_id = path.find("/", start_id + 1);
                continue;
            } else if (start_id != string::npos && end_id == string::npos) {
                string dir = path.substr(start_id+1, string::npos);
                if (dir == "..") { 
                    if (dirs.size() > 0) { dirs.pop_back(); } 
                } else if (dir != "" && dir != ".") { dirs.push_back(dir); }
                break;
            }
        }

        string res = "/";
        for (int i = 0; i < dirs.size(); i++) {
            if (i) { res += "/"; }
            res += dirs[i];
        }

        return res;
    }
};
// @lc code=end

