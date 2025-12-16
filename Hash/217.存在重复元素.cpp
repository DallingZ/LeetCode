/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for(int i = 0; i < nums.size(); i++){
            if(set.count(nums[i])) return true;
            set.insert(nums[i]);
        }
        return false;
    }
};
// @lc code=end

