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

        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int j = 0; j < n-3; j++)
        {

            if (j > 0 && nums[j] == nums[j - 1])
                continue;

            for (int i = j + 1; i < n - 2; i++)
            {
                // 当前的 a 和上一个一样，跳过
                if (i > j + 1 && nums[i] == nums[i - 1])
                    continue;

                int left = i + 1;
                int right = n - 1;
                while (left < right)
                {
                    long long sum = (long long) nums[j] + nums[i] + nums[left] + nums[right];

                    if (sum == target)
                    {

                        result.push_back({nums[j], nums[i], nums[left], nums[right]});
                        // [去重 2] 找到答案后，如果左右两边的数还是重复的，一直跳过
                        // 注意：这步是为了防止出现 [-1, 0, 0, 1, 1] 这种情况下产生多组重复解
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        while (left < right && nums[right] == nums[right - 1])
                            right--;

                        left++;
                        right--;
                    }
                    else if (sum < target)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end
