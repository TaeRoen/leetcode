struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *invertTree(struct TreeNode *root) {
    if (!root) {
        return root;
    }
    struct TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    if (root->left)
        invertTree(root->left);
    if (root->right)
        invertTree(root->right);
    return root;
}