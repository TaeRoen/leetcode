/*
 * @lc app=leetcode id=240 lang=c
 *
 * [240] Search a 2D Matrix II
 */
bool searchMatrix0(int **matrix, int startRow, int endRow, int startCol, int endCol, int target) {
    if (startRow > endRow || startCol > endCol) {
        return false;
    }
    int middleRow = startRow + (endRow - startRow) / 2;
    int middleCol = startCol + (endCol - startCol) / 2;
    int middle = matrix[middleRow][middleCol];
    if (middle == target) {
        return true;
    }
    if (target < middle) {
        bool res1 = searchMatrix0(matrix, startRow, middleRow - 1, startCol, middleCol - 1, target);
        bool res2 = searchMatrix0(matrix, startRow, middleRow - 1, middleCol, endCol, target);
        bool res3 = searchMatrix0(matrix, middleRow, endRow, startCol, middleCol - 1, target);
        return res1 || res2 || res3;
    } else {
        bool res1 = searchMatrix0(matrix, middleRow + 1, endRow, middleCol + 1, endCol, target);
        bool res2 = searchMatrix0(matrix, startRow, middleRow, middleCol + 1, endCol, target);
        bool res3 = searchMatrix0(matrix, middleRow + 1, endRow, startCol, middleCol, target);
        return res1 || res2 || res3;
    }
}

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    return searchMatrix0(matrix,0,matrixRowSize-1,0,matrixColSize-1,target);
}
