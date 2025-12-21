/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> result; // 存放最终结果
    vector<int> path;           // 存放当前路径

    void traversal(TreeNode* node, int count) {
        path.push_back(node->val);
        count -= node->val;

        if (node->left == NULL && node->right == NULL && count == 0) {
            result.push_back(path);
        }

        if (node->left) traversal(node->left, count);
        if (node->right) traversal(node->right, count);

        path.pop_back(); 
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        result.clear();
        path.clear();
        if (root == NULL) return result;
        
        traversal(root, targetSum);
        return result;
    }
};
// @lc code=end

