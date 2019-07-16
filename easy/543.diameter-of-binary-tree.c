/*
 * @lc app=leetcode id=543 lang=c
 *
 * [543] Diameter of Binary Tree
 *
 * https://leetcode.com/problems/diameter-of-binary-tree/description/
 *
 * algorithms
 * Easy (46.25%)
 * Total Accepted:    122.5K
 * Total Submissions: 263.7K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 
 * Given a binary tree, you need to compute the length of the diameter of the
 * tree. The diameter of a binary tree is the length of the longest path
 * between any two nodes in a tree. This path may or may not pass through the
 * root.
 * 
 * 
 * 
 * Example:
 * Given a binary tree 
 * 
 * ⁠         1
 * ⁠        / \
 * ⁠       2   3
 * ⁠      / \     
 * ⁠     4   5    
 * 
 * 
 * 
 * Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
 * 
 * 
 * Note:
 * The length of path between two nodes is represented by the number of edges
 * between them.
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
struct TreeInfo {
    int heigh;
    int length;
};

struct TreeInfo analyse(struct TreeNode *root) {
    struct TreeInfo info;
    if (!root) {
        return info;
    }
    struct TreeInfo left = analyse(root->left);
    struct TreeInfo right = analyse(root->right);
    info.heigh = left.heigh > right.heigh ? left.heigh + 1 : right.heigh + 1;
    info.length = left.heigh + right.heigh + 1;
    if (info.length < left.length) {
        info.length = left.length;
    }
    if (info.length < right.length) {
        info.length = right.length;
    }
    return info;
}

int diameterOfBinaryTree(struct TreeNode *root) {
    if (!root) {
        return 0;
    }
    return analyse(root).length - 1;
}

