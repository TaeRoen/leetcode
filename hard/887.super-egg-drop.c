/*
 * @lc app=leetcode id=887 lang=c
 *
 * [887] Super Egg Drop
 */


int superEggDrop(int K, int N) {
    int dp[N+2][K+2];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 0;
    for (int m = 1; m <= N; m++) {
        dp[m][0] = 0;
        for (int k = 1; k <= K; k++) {
            dp[m][k] = dp[m-1][k] + dp[m-1][k-1] + 1;
            if (dp[m][k] >= N) {
                return m;
            }
        }
    }
    return N;
}


