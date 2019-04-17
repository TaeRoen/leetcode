struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int dfs(struct TreeNode *root, int sum) {
    if (!root) {
        return 0;
    }
    int res = 0;
    if (root->val == sum) {
        res++;
    }
    res += dfs(root->left, sum - root->val);
    res += dfs(root->right, sum - root->val);
    return res;
}

int pathSum(struct TreeNode *root, int sum) {
    if (root == 0) {
        return 0;
    } else {
        return dfs(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
}