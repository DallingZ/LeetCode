/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        TreeNode* k = root;
        int left = 0, right = 0;
        // 剪枝
        while(k != NULL){
            k = k->left;
            left ++;
        }
        k = root;
        while(k != NULL){
            k = k->right;
            right ++;
        }

        // 满二叉树直接返回2^n -1
        if(left == right) return (1 << left) - 1;
        // 否则遍历
        else{
            int leftNum = countNodes(root->left);
            int rightNum = countNodes(root->right);
            return leftNum + rightNum + 1;
        }

    }
};
// @lc code=end

