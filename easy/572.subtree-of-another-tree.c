/*
 * @lc app=leetcode id=572 lang=c
 *
 * [572] Subtree of Another Tree
 *
 * https://leetcode.com/problems/subtree-of-another-tree/description/
 *
 * algorithms
 * Easy (41.33%)
 * Total Accepted:    95.9K
 * Total Submissions: 230.9K
 * Testcase Example:  '[3,4,5,1,2]\n[4,1,2]'
 *
 * 
 * Given two non-empty binary trees s and t, check whether tree t has exactly
 * the same structure and node values with a subtree of s. A subtree of s is a
 * tree consists of a node in s and all of this node's descendants. The tree s
 * could also be considered as a subtree of itself.
 * 
 * 
 * Example 1:
 * 
 * Given tree s:
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \
 * ⁠1   2
 * 
 * Given tree t:
 * 
 * ⁠  4 
 * ⁠ / \
 * ⁠1   2
 * 
 * Return true, because t has the same structure and node values with a subtree
 * of s.
 * 
 * 
 * Example 2:
 * 
 * Given tree s:
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \
 * ⁠1   2
 * ⁠   /
 * ⁠  0
 * 
 * Given tree t:
 * 
 * ⁠  4
 * ⁠ / \
 * ⁠1   2
 * 
 * Return false.
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
bool isSameTree(struct TreeNode *s, struct TreeNode *t) {
    if (s && t) {
        if (s->val == t->val) {
            return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
        } else {
            return false;
        }
    } else if (s == t) {
        return true;
    }
    return false;
}

bool isSubtree(struct TreeNode *s, struct TreeNode *t) {
    if (isSameTree(s, t)) {
        return true;
    } else {
        if (s->left && s->right) {
            return isSubtree(s->left, t) || isSubtree(s->right, t);
        } else {
            if (s->left) {
                return isSubtree(s->left, t);
            }
            if (s->right) {
                return isSubtree(s->right, t);
            }
        }
        return false;
    }
}

