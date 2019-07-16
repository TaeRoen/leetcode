/*
 * @lc app=leetcode id=461 lang=c
 *
 * [461] Hamming Distance
 *
 * https://leetcode.com/problems/hamming-distance/description/
 *
 * algorithms
 * Easy (70.07%)
 * Total Accepted:    229.4K
 * Total Submissions: 326.9K
 * Testcase Example:  '1\n4'
 *
 * The Hamming distance between two integers is the number of positions at
 * which the corresponding bits are different.
 * 
 * Given two integers x and y, calculate the Hamming distance.
 * 
 * Note:
 * 0 ≤ x, y < 2^31.
 * 
 * 
 * Example:
 * 
 * Input: x = 1, y = 4
 * 
 * Output: 2
 * 
 * Explanation:
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
 * ⁠      ↑   ↑
 * 
 * The above arrows point to positions where the corresponding bits are
 * different.
 * 
 * 
 */
int hammingDistance(int x, int y) {
    int res = 0;
    while (x != 0 || y != 0) {
        if (x % 2 != y % 2) {
            res++;
        }
        x /= 2;
        y /= 2;
    }
    return res;
}

