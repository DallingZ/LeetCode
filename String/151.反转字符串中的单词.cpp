/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int slow = 0; 
        for (int fast = 0; fast < s.size(); fast++) {
            if (s[fast] != ' ') {
                if (slow != 0) s[slow++] = ' ';
                
                while (fast < s.size() && s[fast] != ' ') {
                    s[slow++] = s[fast++]; //先赋值，再++；
                }
            }
        }

        s.resize(slow);

        // reverse 左闭右开
        reverse(s.begin(), s.end());
        int j = 0;
        for(int i = 0; i < s.size(); i++){
            if(i == s.size() -1 || s[i + 1] == ' ') {
                reverse(s.begin() + j, s.begin() + i + 1);
                j = i + 2;
            }
        }
        return s;
    }
};
// @lc code=end

