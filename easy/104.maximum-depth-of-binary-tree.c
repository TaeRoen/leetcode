/*
 * @lc app=leetcode id=104 lang=c
 *
 * [104] Maximum Depth of Binary Tree
 *
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (59.38%)
 * Total Accepted:    485.2K
 * Total Submissions: 809.3K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its maximum depth.
 * 
 * The maximum depth is the number of nodes along the longest path from the
 * root node down to the farthest leaf node.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * return its depth = 3.
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode *root)
{
    if(!root){
        return 0;
    }
    if (root->left && root->right)
    {
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return (left > right ? left : right) + 1;
    }
    else if (!root->left && !root->right)
    {
        return 1;
    }
    else
    {
        if (root->left)
        {
            return maxDepth(root->left) + 1;
        }
        else
        {
            return maxDepth(root->right) + 1;
        }
    }
}

