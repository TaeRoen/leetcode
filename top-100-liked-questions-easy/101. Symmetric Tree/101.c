struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

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