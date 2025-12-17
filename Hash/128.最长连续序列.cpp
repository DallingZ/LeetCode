/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0; //空
        unordered_set<int> st(nums.begin(), nums.end());
        
        int longestStreak = 0;
        for (int num : st) {
            //当前数有没有前面的数
            if (!st.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;
                // 往后数
                while (st.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
};
// @lc code=end

