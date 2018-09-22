struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

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