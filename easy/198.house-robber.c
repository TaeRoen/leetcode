/*
 * @lc app=leetcode id=198 lang=c
 *
 * [198] House Robber
 *
 * https://leetcode.com/problems/house-robber/description/
 *
 * algorithms
 * Easy (40.81%)
 * Total Accepted:    307.5K
 * Total Submissions: 751.9K
 * Testcase Example:  '[1,2,3,1]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping
 * you from robbing each of them is that adjacent houses have security system
 * connected and it will automatically contact the police if two adjacent
 * houses were broken into on the same night.
 * 
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money =
 * 3).
 * Total amount you can rob = 1 + 3 = 4.
 * 
 * Example 2:
 * 
 * 
 * Input: [2,7,9,3,1]
 * Output: 12
 * Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house
 * 5 (money = 1).
 * Total amount you can rob = 2 + 9 + 1 = 12.
 * 
 * 
 */
int rob(int *nums, int numsSize) {
    if (numsSize == 1) {
        return nums[0];
    }
    if (numsSize == 2) {
        return nums[0] > nums[1] ? nums[0] : nums[1];
    }
    int *res = (int *)malloc(sizeof(int) * numsSize);
    res[0] = nums[0];
    res[1] = nums[0] > nums[1] ? nums[0] : nums[1];

    for (int i = 2; i < numsSize; i++) {
        if (nums[i] + res[i - 2] > res[i - 1]) {
            res[i] = nums[i] + res[i - 2];
        } else {
            res[i] = res[i - 1];
        }
    }
    return res[numsSize - 1];
}

