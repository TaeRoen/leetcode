int climbStairs(int n) {
    // last step is 1
    int *res1 = (int *)malloc(sizeof(int) * (n));
    // last step is 2
    int *res2 = (int *)malloc(sizeof(int) * (n));

    res1[0] = 1;
    res2[0] = 0;
    for (int i = 1; i < n; i++) {
        res1[i] = res1[i - 1] + res2[i - 1];
        res2[i] = res1[i - 1];
    }
    return res1[n - 1] + res2[n - 1];
}