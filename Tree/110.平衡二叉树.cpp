/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    int getH(TreeNode* tree){
        if(tree == NULL) return 0;

        int leftH = getH(tree->left);
        // 如果下面报错，那直接往上报错
        if(leftH == -1) return -1;
        int rightH = getH(tree->right);
        if(rightH == -1) return -1;

        if(abs(leftH - rightH) > 1){
            return -1;
        }else{
            return max(leftH, rightH) +1;
        }
    }
    bool isBalanced(TreeNode* root) {
        return getH(root) != -1;
    }
};
// @lc code=end

