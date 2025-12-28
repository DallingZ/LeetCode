/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> resulat;
    vector<int> now;
    int index = 1;
    void Tracking(int k, int n, int index){
        if(n < 0) return;
        if(k == 0){
            if(n == 0)
            resulat.push_back(now);
            return ; 
        }
        for(int i = index; i <= 9; i++){
            now.push_back(i);
            Tracking(k - 1, n - i, i + 1);
            now.pop_back();
        }
        return ;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        resulat.clear();
        now.clear();
        Tracking(k, n, index);
        return resulat;
    }
};
// @lc code=end

