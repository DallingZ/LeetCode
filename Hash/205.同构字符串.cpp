/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        int mapS[256] = {};
        int mapT[256] = {};
        for (int i = 0; i < s.size(); i++)
        {
            // 如果两个字符上一次出现的位置不一样，说明映射关系乱了
            if (mapS[s[i]] != mapT[t[i]])
            {
                return false;
            }
            mapS[s[i]] = i + 1;
            mapT[t[i]] = i + 1;
        }
        return true;
    }
};

// @lc code=end
