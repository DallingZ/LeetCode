/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int left, right;
        int n = nums.size();
        if (n < 4) return {};
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++)
        {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                if ((long)nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                if ((long)nums[i] + nums[j] + nums[n-2] + nums[n-1] < target) continue;
                if(j > i + 1 && nums[j] == nums[j-1]) continue;

                left = j + 1;
                right = n - 1;

                while(left < right){
                    long sum = (long)nums[left] + nums[right] + nums[i] + nums[j];
                    if(sum == target){
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while(left < right && nums[left] == nums[left+1]) left ++;
                        while(left < right && nums[right] == nums[right-1]) right --;

                        left ++;
                        right --;
                    }
                    else if(sum < target) left ++;
                    else right --;
                }
            }
        }
        return result;
    }
};
// @lc code=end
