/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second; // 谁的次数大，谁排前面
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]] += 1;
        }
        vector<pair<int, int>> vec;
        for (auto item : map) {
            vec.push_back(item); 
        }
        sort(vec.begin(), vec.end(), cmp);

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(vec[i].first);
        }
        return result;
    }
};
// @lc code=end

