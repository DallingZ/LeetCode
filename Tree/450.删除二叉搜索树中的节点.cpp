/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return root;
        if (root->val == key) {
            // 左边是空的
            if (root->left == NULL) return root->right;
            // 右边是空的
            else if (root->right == NULL) return root->left;
            else {
                // 找到右子树里最左边的那个节点
                TreeNode* cur = root->right;
                while(cur->left != NULL) {
                    cur = cur->left;
                }
                cur->left = root->left;
                return root->right;
            }
        }

        if (root->val > key) root->left = deleteNode(root->left, key);
        if (root->val < key) root->right = deleteNode(root->right, key);
        
        return root;
    }
};
// @lc code=end

