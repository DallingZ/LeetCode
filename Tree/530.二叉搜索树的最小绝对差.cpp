/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
        if(tree == NULL) return;
        //中序遍历
        getNum(tree->left);
        k.push_back(tree->val);    
        getNum(tree->right);
    }
    int getMinimumDifference(TreeNode* root) {
        k.clear();
        getNum(root);
        int n = k.size();
        int min = INT_MAX;
        for(int i = 1; i < n; i ++){
            int diff = k[i] - k[i-1];
            if(diff < min) {
                    min = diff;
            }
        }
        return min;
    }
};
// @lc code=end

