/*
 * @lc app=leetcode id=538 lang=c
 *
 * [538] Convert BST to Greater Tree
 *
 * https://leetcode.com/problems/convert-bst-to-greater-tree/description/
 *
 * algorithms
 * Easy (50.06%)
 * Total Accepted:    74.3K
 * Total Submissions: 147.2K
 * Testcase Example:  '[5,2,13]'
 *
 * Given a Binary Search Tree (BST), convert it to a Greater Tree such that
 * every key of the original BST is changed to the original key plus sum of all
 * keys greater than the original key in BST.
 * 
 * 
 * Example:
 * 
 * Input: The root of a Binary Search Tree like this:
 * ⁠             5
 * ⁠           /   \
 * ⁠          2     13
 * 
 * Output: The root of a Greater Tree like this:
 * ⁠            18
 * ⁠           /   \
 * ⁠         20     13
 * 
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
int addTree(struct TreeNode *root, int x) {
    if (!root) {
        return x;
    }
    int right = addTree(root->right, x);
    root->val += right;
    return addTree(root->left, root->val);
}

struct TreeNode *convertBST(struct TreeNode *root) {
    addTree(root, 0);
    return root;
}

