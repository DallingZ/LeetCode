/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
        //从上往下交换
    void trans(TreeNode* root){
        if(root == NULL) return;
        // 不管左右是否空直接交换
        TreeNode* k = root->left;
        root->left = root->right;
        root->right = k;

        //递归
        trans(root->left);
        trans(root->right);

    }
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        trans(root);
        return root;
    }
};
// @lc code=end

