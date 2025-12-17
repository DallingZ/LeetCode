/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size() > magazine.size()) return false;
        int map[26] = {};
        for(int i = 0; i < magazine.size(); i++){
            map[magazine[i] - 'a'] ++;
        }
        for(int j = 0; j< ransomNote.size(); j++){
            map[ransomNote[j] - 'a'] --;
            if(map[ransomNote[j] - 'a'] < 0) return false;
        }
        return true;
    }
};
// @lc code=end

