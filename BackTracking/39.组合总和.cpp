/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> now;
    void get(vector<int>& candidates, int target, int startIndex){
        if(target < 0) return;
        if(target == 0){
            result.push_back(now);
            return;
        }

        for(int i = startIndex; i < candidates.size(); i++){
            now.push_back(candidates[i]);
            get(candidates, target - candidates[i], i);   
            now.pop_back(); 
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        now.clear();
        get(candidates, target, 0);
        return result;
    }
};
// @lc code=end

