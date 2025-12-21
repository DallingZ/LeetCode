/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int depthmin = 1;
        queue<TreeNode*> line;
        line.push(root);
        while(!line.empty()){
            int n = line.size();
            for(int i = 0; i < n; i++){
                TreeNode* k = line.front();
                line.pop();
                if(k->left == NULL && k->right == NULL) return depthmin;
                if(k->left != NULL)
                    line.push(k->left);
                if(k->right != NULL)
                    line.push(k->right);
            }
            depthmin ++;
        } 
        return depthmin;
    }
};
// @lc code=end

