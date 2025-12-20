/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    void traversal(TreeNode* tree, vector<int>& vec){
        if(tree == NULL) return;
        traversal(tree->left, vec);
        traversal(tree->right, vec);
        vec.push_back(tree->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vect;
        traversal(root, vect);
        return vect;
    }
};
// @lc code=end

