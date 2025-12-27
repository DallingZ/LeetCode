/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result; 
    vector<int> path;      

    // startIndex: 用来记录本层递归是从哪里开始遍历的
    // 防止出现 [1,2] 和 [2,1] 这种重复
    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i <= n; i++) {       
            path.push_back(i);
            backtracking(n, k, i + 1); 
            path.pop_back();   
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        result.clear();
        path.clear();
        backtracking(n, k, 1); // 从 1 开始选
        return result;

    }
};
// @lc code=end

