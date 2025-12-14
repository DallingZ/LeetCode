/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         unordered_map<char, int> map;
//         int num = 0, max = 0, left = 0, right = 0;
//         for(right = 0; right < s.size(); right++){
//             if(map.find(s[right]) == map.end()){
//                 map[s[right]] = right;
//                 num ++;
//                 if(num > max) max = num;
//             }
//             else {
//                 while((map.find(s[right]) != map.end()))
//                 {
//                     map.erase(s[left]);
//                     left ++;
//                     num --;
//                 }
//                 num ++;
//                 map[s[right]] = right;
//             }
//         }
//         return max;
//     }
// };                 第一次做，两个指针实现滑动窗口
//          第二次做极简，先处理异常
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int maxL = 0, left = 0;
        for(int right = 0; right < s.size(); right++){
            //先处理异常：找到重复的
            while(window.count(s[right])){
                window.erase(s[left]);
                left ++;
            }

            //正常加入set
            window.insert(s[right]);
            maxL = max(maxL, right - left +1);
        }
        return maxL;
    }
};
// @lc code=end

