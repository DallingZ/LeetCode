/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0};
        int col[9][9] = {0};
        int num[3][3][9] = {0};
        for(int i = 0; i < 9; i++){
            for(int j = 0; j <9; j++){
                char now = board[i][j];
                // 跳过空格
                if(now == '.') continue;

                int k = now - '1';
                
                //三个情况全部返回false
                if(row[i][k] == 1) return false;
                if(col[j][k] == 1) return false;
                if(num[i/3][j/3][k] == 1) return false;
                
                //没出现就对应置为1
                row[i][k] = 1;
                col[j][k] = 1;
                num[i/3][j/3][k] = 1;
            }
        }
        return true;
    }
};
// @lc code=end

