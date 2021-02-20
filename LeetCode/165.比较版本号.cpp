/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

// @lc code=start

int str2int(string str) {
    int res = 0;
    for (int i = 0; i < str.size(); i++) {
        res *= 10;
        res += (str[i] - '0');
    }

    return res;
}

void split(vector<int>& nums, string str) {
    int start = 0;
    for (; start < str.size(); start++) {
        if (str[start] == '.') { continue; }
        int end = start;
        while (end < str.size() && str[end] != '.') { end++; }

        nums.push_back(str2int(str.substr(start, end-start)));
        start = end;
    }
}

struct Version {
    vector<int> nums;

    Version(string str) {
        split(nums, str);
    }
};

class Solution {
public:
    int compareVersion(string version1, string version2) {
        Version v1(version1);
        Version v2(version2);

        int i = 0;
        while (i < v1.nums.size() && i < v2.nums.size()) {
            if (v1.nums[i] > v2.nums[i]) { return 1; }
            else if (v1.nums[i] < v2.nums[i]) { return -1; }
            i++;
        }

        while (i < v1.nums.size()) {
            if (v1.nums[i++] > 0) { return 1; }
        }

        while (i < v2.nums.size()) {
            if (v2.nums[i++] > 0) { return -1; }
        }

        return 0;
    }
};
// @lc code=end

