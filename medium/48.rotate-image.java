/*
 * @lc app=leetcode id=48 lang=java
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
    private void rotateSub(int[][] matrix, int sub) {
        int start = sub;
        int end = matrix.length - 1 - sub;
        int tmp = matrix[start][start];
        matrix[start][start] = matrix[end][start];
        matrix[end][start] = matrix[end][end];
        matrix[end][end] = matrix[start][end];
        matrix[start][end] = tmp;
        for (int i = 1; i < end - start; i++) {
            tmp = matrix[start][start + i];
            matrix[start][start + i] = matrix[end - i][start];
            matrix[end - i][start] = matrix[end][end - i];
            matrix[end][end - i] = matrix[start + i][end];
            matrix[start + i][end] = tmp;
        }
    }

    public void rotate(int[][] matrix) {
        for (int i = 0; i < matrix.length / 2; i++) {
            rotateSub(matrix, i);
        }
    }
}
// @lc code=end
