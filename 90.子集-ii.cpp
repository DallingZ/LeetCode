/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> now;
    void trackBack(vector<int>& nums, int index){
        result.push_back(now);
        if(index >= nums.size()) return ;

        for(int i = index; i < nums.size(); i++){
            if (i > index && nums[i] == nums[i-1]) {
                continue;
            }
            now.push_back(nums[i]);
            trackBack(nums, i + 1);
            now.pop_back();
        }
        return ;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        result.clear();
        now.clear();
        sort(nums.begin(), nums.end());
        trackBack(nums, 0);
        return result;
    }
};
// @lc code=end

