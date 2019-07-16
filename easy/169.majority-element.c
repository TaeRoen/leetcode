/*
 * @lc app=leetcode id=169 lang=c
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (51.65%)
 * Total Accepted:    367.6K
 * Total Submissions: 705.3K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 */
int majorityElement(int *nums, int numsSize) {
    int *elements = (int *)malloc(sizeof(int) * numsSize);
    int *counts = (int *)malloc(sizeof(int) * numsSize);

    int element_count = 0;
    for (int i = 0; i < numsSize; i++) {
        bool isSave = false;
        for (int j = 0; j < element_count; j++) {
            if (elements[j] == nums[i]) {
                isSave = true;
                counts[j]++;
                if (counts[j] > numsSize / 2) {
                    return nums[i];
                }
            }
        }
        if (!isSave) {
            elements[element_count] = nums[i];
            counts[element_count] = 1;
            element_count++;
        }
    }
    return nums[0];
}
