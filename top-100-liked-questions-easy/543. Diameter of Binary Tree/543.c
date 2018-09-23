struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

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