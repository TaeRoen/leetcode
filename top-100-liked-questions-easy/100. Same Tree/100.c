struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode *p, struct TreeNode *q) {
    if (p == 0 && q == 0) {
        return true;
    }
    if (p == 0 || q == 0) {
        return false;
    }
    if (p->val == q->val) {
        if (isSameTree(p->left, q->left) && isSameTree(p->right, q->right)) {
            return true;
        }
    }
    return false;
}