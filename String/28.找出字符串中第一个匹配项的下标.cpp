/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        //  暴力
        // int n = haystack.size();
        // int m = needle.size();
        // for (int i = 0; i <= n - m; i++) {
        //     int j = 0;
        //     for (j = 0; j < m; j++) {
        //         if (haystack[i + j] != needle[j]) {
        //             break; 
        //         }
        //     }
        //     if (j == m) {
        //         return i;
        //     }
        // }
        // return -1;

        if (needle.size() == 0) return 0;
        //求next
        vector<int> next(needle.size()); 
        int j = 0;
        next[0] = 0;

        for(int i = 1; i < needle.size(); i++) {
            // 不匹配，持续回退 
            while (j > 0 && needle[i] != needle[j]) {
                j = next[j - 1]; 
            }
            // 匹配
            if (needle[i] == needle[j]) {
                j++;
            }
            next[i] = j;
        }

        // 匹配
        j = 0; // j 代表 needle 目前匹配了多长
        for(int i = 0; i < haystack.size(); i++) {  
            // 不匹配时
            while(j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }

            // 匹配
            if(haystack[i] == needle[j]) {
                j++;
            }

            if(j == needle.size()) {
                return i - needle.size() + 1;
            }
        }

        return -1;
    }
};
// @lc code=end

