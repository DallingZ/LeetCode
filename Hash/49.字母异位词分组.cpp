/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        //主要是怎么设计key和value
        for(string s : strs){
            string temp = s;
            sort(temp.begin(), temp.end());
            map[temp].push_back(s);
        }
        vector<vector<string>> result;
        for(auto [key, value] : map){
            result.push_back(value);
        }
        return result;
    }
};
// @lc code=end

