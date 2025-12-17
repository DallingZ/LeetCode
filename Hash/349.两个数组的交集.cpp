/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set;
        vector<int> real;
        for(int i = 0; i < nums1.size(); i++){
            set.insert(nums1[i]);
        }
        for(int j = 0; j < nums2.size(); j++){
            if(set.count(nums2[j])) {
                real.push_back(nums2[j]);
                set.erase(nums2[j]);
            }
        }
        return real;

    }
};
// @lc code=end

