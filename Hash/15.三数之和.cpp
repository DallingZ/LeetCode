/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            // 最小的数都已经 > 0，后面肯定凑不出 0 了 
            if (nums[i] > 0) break;
            // 当前的 a 和上一个一样，跳过 
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {

                    result.push_back({nums[i], nums[left], nums[right]});
                    // 左右两边的数还是重复的，一直跳过
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                } 
                else if (sum < 0) {
                    left++; 
                } 
                else {
                    right--; 
                }
            }
        }
        return result;
    }
};
// @lc code=end

