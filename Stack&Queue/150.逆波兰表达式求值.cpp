/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st; 

        for (int i = 0; i < tokens.size(); i++) {
            string s = tokens[i]; 

            if (s == "+" || s == "-" || s == "*" || s == "/") {
                long long num2 = st.top(); st.pop(); 
                long long num1 = st.top(); st.pop(); 

                if (s == "+") st.push(num1 + num2);
                if (s == "-") st.push(num1 - num2);
                if (s == "*") st.push(num1 * num2);
                if (s == "/") st.push(num1 / num2);
            } 
            else {
                st.push(stoll(s));
            }
        }
        
        return st.top();
    }
};
// @lc code=end

