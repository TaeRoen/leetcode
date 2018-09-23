int uniquePaths(int m, int n) {
    if(m == 1 || n == 1){
        return 1;
    }

    int **grid = (int **)malloc(sizeof(int *) * m);

    for (int i = 0; i < m; i++) {
        grid[i] = (int *)malloc(sizeof(int) * n);
    }

    grid[0][0] = 0;
    for (int i = 1; i < m; i++) {
        grid[i][0] = 1;
    }
    for (int i = 1; i < n; i++) {
        grid[0][i] = 1;
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
        }
    }

    return grid[m-1][n-1];
}