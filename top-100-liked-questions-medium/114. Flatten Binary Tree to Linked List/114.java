public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class Solution {
    public class RightNode {
        TreeNode head;
        TreeNode tail;

        RightNode(TreeNode node) {
            head = node;
            tail = node;
        }

        void addRight(TreeNode node) {
            tail.left = null;
            tail.right = node;
            tail = node;
        }
    }

    public void traverse(TreeNode root, RightNode node) {
        if (root) {
            node.addRight(root);
            traverse(root.left, node);
            traverse(root.riht, node);
        }
    }

    public void flatten(TreeNode root) {
        if (root) {
            RightNode node = new RightNode(root);
            traverse(root.left, node);
            traverse(root.right, node);
        }
    }
}