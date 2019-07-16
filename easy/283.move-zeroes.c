/*
 * @lc app=leetcode id=283 lang=c
 *
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (53.70%)
 * Total Accepted:    446.8K
 * Total Submissions: 827.1K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * 
 * Note:
 * 
 * 
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 */
void moveZeroes(int *nums, int numsSize) {
    for (int i = 1; i < numsSize; i++) {
        if (nums[i - 1] == 0 && nums[i] != 0) {
            int j = i - 1;
            while (j > 0 && nums[j - 1] == 0) {
                j--;
            }
            nums[j] = nums[i];
            nums[i] = 0;
        }
    }
}

