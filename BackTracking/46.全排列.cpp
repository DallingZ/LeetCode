/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> now;
    
    void Tracking(vector<int>& nums, vector<bool>& used){
        if(now.size() == nums.size()){
            result.push_back(now);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if (used[i] == true) continue;

            used[i] = true;
            now.push_back(nums[i]);
            Tracking(nums, used);
            now.pop_back();      
            used[i] = false;   
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        result.clear();
        now.clear();
        vector<bool> used(nums.size(), false);
        
        Tracking(nums, used);
        return result;
    }
};
// @lc code=end

