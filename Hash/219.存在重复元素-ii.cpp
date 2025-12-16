/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       unordered_map<int, int> map;
       for(int i = 0; i < nums.size(); i++){
        if((map.find(nums[i]) != map.end()) && abs(map[nums[i]] - i) <= k) return true;
        map[nums[i]] = i;
        //类似于滑动窗口，减少存储空间
        if (map.size() > k) map.erase(nums[i - k]);
       } 
       return false;
    }
};
// @lc code=end

