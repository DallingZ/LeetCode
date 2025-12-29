/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
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
            now.push_back(nums[i]);
            trackBack(nums, i + 1);
            now.pop_back();
        }
        return ;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        trackBack(nums, 0);
        return result;
    }
};
// @lc code=end

