/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
    const string letterMap[10] = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

public:
    vector<string> result;
    string s; 

    void Tracking(const string& digits, int index) {
         if (index == digits.size()) {
            result.push_back(s); 
            return;
        }
        int digit = digits[index] - '0'; 
        string letters = letterMap[digit]; // 拿到 "abc"

        for (int i = 0; i < letters.size(); i++) {
            s.push_back(letters[i]); 
            Tracking(digits, index + 1);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        result.clear();
        s.clear();
        if (digits.size() == 0) return result; 
        
        Tracking(digits, 0); 
        return result;
    }
};
// @lc code=end

