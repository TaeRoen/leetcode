struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *mergeTrees(struct TreeNode *t1, struct TreeNode *t2) {
    if (t1 || t2) {
        if (t1 == NULL) {
            return t2;
        } else if (t2 == NULL) {
            return t1;
        } else {
            t1->val += t2->val;
            t1->left = mergeTrees(t2->left, t1->left);
            t1->right = mergeTrees(t2->right, t1->right);
        }
        return t1;
    } else {
        return NULL;
    }
}