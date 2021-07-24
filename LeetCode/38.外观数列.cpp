class Solution {
public:
    string next(string& str) {
        string res = "";
        char pre = str[0];
        int cnt = 1;
        for (int i = 1; i < str.size(); i++) {
            if (str[i] == pre) {
                cnt += 1;
                continue;
            }
            
            res += (to_string(cnt) + pre);
            pre = str[i];
            cnt = 1;
        }

        res += (to_string(cnt) + pre);
        return res;
    }

    string countAndSay(int n) {
        string res = "1";
        if (1 == n) { return res; }

        for (int i = 2; i <= n; i++) {
            res = next(res);
        }
        return res;
    }
};