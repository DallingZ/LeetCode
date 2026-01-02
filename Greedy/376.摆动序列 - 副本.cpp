/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();

        int curDiff = 0; // 当前一对元素的差值
        int preDiff = 0; // 前一对元素的差值
        int result = 1;  // 记录峰值的个数，默认序列最右边有一个峰值，所以初始为 1

        for (int i = 0; i < nums.size() - 1; i++) {
            // 计算当前坡度
            curDiff = nums[i + 1] - nums[i];

            // 贪心判断：出现“峰”或“谷”
            // (preDiff <= 0 && curDiff > 0) -> 之前下坡或平坡，现在上坡（山谷）
            // (preDiff >= 0 && curDiff < 0) -> 之前上坡或平坡，现在下坡（山峰）
            if ((preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0)) {
                result++;
                
                // 【关键细节】只有发生了摆动，才更新 preDiff
                // 这样可以处理单调区间里的平坡问题
                preDiff = curDiff;
            }
        }
        return result;
    }
};
// @lc code=end

//[1,17,5,10,13,15,10,5,16,8]
// 16 -12 5 3 2 -5 -5 11 -8