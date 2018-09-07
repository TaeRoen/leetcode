struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode *root)
{
    if(!root){
        return 0;
    }
    if (root->left && root->right)
    {
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return (left > right ? left : right) + 1;
    }
    else if (!root->left && !root->right)
    {
        return 1;
    }
    else
    {
        if (root->left)
        {
            return maxDepth(root->left) + 1;
        }
        else
        {
            return maxDepth(root->right) + 1;
        }
    }
}