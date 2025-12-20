/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 != 0 ) return false;
        stack<char> a;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') 
                a.push(s[i]);
            else {
                if (a.empty()) return false;

                char top = a.top();
                if (s[i] == ')' && top == '(') a.pop();
                else if (s[i] == ']' && top == '[') a.pop();
                else if (s[i] == '}' && top == '{') a.pop();
                else return false; // 匹配失败
            } 
        }
        return a.empty();
    }
};
// @lc code=end

