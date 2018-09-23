int minPathSum(int **grid, int gridRowSize, int gridColSize) {
    int **res = (int **)malloc(sizeof(int *) * gridRowSize);

    for (int i = 0; i < gridRowSize; i++) {
        res[i] = (int *)malloc(sizeof(int) * gridColSize);
        for (int j = 0; j < gridColSize; j++) {
            res[i][j] = 0;
        }
    }

    res[0][0] = grid[0][0];

    for (int i = 1; i < gridColSize; i++) {
        res[0][i] = res[0][i - 1] + grid[0][i];
    }

    for (int i = 1; i < gridRowSize; i++) {
        res[i][0] = res[i - 1][0] + grid[i][0];
    }

    for (int i = 1; i < gridRowSize; i++) {
        for (int j = 1; j < gridColSize; j++) {
            res[i][j] = res[i - 1][j] < res[i][j - 1] ? res[i - 1][j] + grid[i][j] : res[i][j - 1] + grid[i][j];
        }
    }
    return res[gridRowSize - 1][gridColSize - 1];
}