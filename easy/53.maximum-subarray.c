/*
 * @lc app=leetcode id=53 lang=c
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (42.92%)
 * Total Accepted:    502.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */
int maxSubArray(int *nums, int numsSize) {
    int max = nums[0], tmp_sum = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (tmp_sum > 0) {
            tmp_sum += nums[i];
        } else {
            tmp_sum = nums[i];
        }
        if (max < tmp_sum) {
            max = tmp_sum;
        }
    }
    return max;
}

