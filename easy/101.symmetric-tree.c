/*
 * @lc app=leetcode id=101 lang=c
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (42.81%)
 * Total Accepted:    383.2K
 * Total Submissions: 888.4K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 * 
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * But the following [1,2,2,null,3,null,3]  is not:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
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
bool isSymmetricTwoTree(struct TreeNode *left, struct TreeNode *right) {
    if (left && right) {
        if (left->val == right->val) {
            return isSymmetricTwoTree(left->left, right->right) && isSymmetricTwoTree(right->left, left->right);
        } else {
            return false;
        }
    } else if (!left && !right) {
        return true;
    } else {
        return false;
    }
}

bool isSymmetric(struct TreeNode *root) {
    if (!root) {
        return true;
    }
    return isSymmetricTwoTree(root->left, root->right);
}

