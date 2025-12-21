/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode* root) {
    if(root == NULL) return 0;
    queue<TreeNode*> k;
    k.push(root);
    int depth = 0;
    while(!k.empty()){
        int n = k.size();
        for(int i = 0; i < n; i++){
            TreeNode* j = k.front();
            k.pop();
            if(j->left != NULL)
                k.push(j->left);
            if(j->right != NULL)
                k.push(j->right);
        }
        depth ++;

       } 
       return depth;
    }
};
// @lc code=end

