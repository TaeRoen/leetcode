/*
 * @lc app=leetcode id=69 lang=c
 *
 * [69] Sqrt(x)
 */

// @lc code=start

int mySqrt(int x) {
    int i;
    for (i = 0; i <= 46340; i++) {
        int t = (int)(i * i);
        if (t < x) {
            continue;
        }
        if (t == x) {
            return i;
        }
        if (t > x) {
            return i - 1;
        }
    }
    return i - 1;
}
// @lc code=end
