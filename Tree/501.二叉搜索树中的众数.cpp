/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> k;
    void getNum(TreeNode* tree){
        if(tree == NULL)    return;
        //中序遍历
        getNum(tree->left);
        k.push_back(tree->val);
        getNum(tree->right);
    }
    vector<int> findMode(TreeNode* root) {
        k.clear();
        getNum(root);
        
        if (k.empty()) return {};

        vector<int> result; 
        int maxCount = 0;   
        int count = 0;  

        for(int i = 0; i < k.size(); i++){
            if (i == 0 || k[i] == k[i-1]) {
                count++;
            } else {
                count = 1;
            }

            if (count > maxCount) {
                maxCount = count;
                result.clear();     
                result.push_back(k[i]); 
            } 
            else if (count == maxCount) {
                result.push_back(k[i]);
            }
        }
        
        return result;

    }
};
// @lc code=end

