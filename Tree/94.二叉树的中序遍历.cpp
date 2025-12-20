/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    void travelsal(TreeNode* tree, vector<int>& vec){
        if(tree == NULL) return;
        travelsal(tree->left, vec);
        vec.push_back(tree->val);
        travelsal(tree->right, vec);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vect;
        travelsal(root, vect);
        return vect;
    }
};
// @lc code=end

