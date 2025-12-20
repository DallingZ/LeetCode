/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        string a = "";
        for(int i = 0; i < s.size(); i++){
            if(!a.empty() && s[i] == a.back()) a.pop_back();
            else a.push_back(s[i]);
        }
        return a;
    }
};
// @lc code=end

