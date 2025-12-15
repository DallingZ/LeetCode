/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start


// 空间复杂度O（1）
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        for(int i = 0; i < nums.size(); i++){
           a ^= nums[i];
        }
        return a;
    }
};

//第一次做 hash消除重复的
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         unordered_set<int> set;
//         for(int i = 0; i < nums.size(); i++){
//             if(set.find(nums[i]) != set.end()){
//                 set.erase(nums[i]);
//             }
//             else set.insert(nums[i]);
//         }
//         return *set.begin();
//     }
// };
// @lc code=end

