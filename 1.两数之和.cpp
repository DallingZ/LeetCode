/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int ,int> map;

        for(int i = 0; i < nums.size(); i++){
            int need = target - nums[i];
            if(map.find(need) != map.end())
                return {map[need], i};
            map[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

