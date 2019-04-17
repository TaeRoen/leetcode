
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

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