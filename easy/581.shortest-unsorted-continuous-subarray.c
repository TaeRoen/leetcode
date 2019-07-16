/*
 * @lc app=leetcode id=581 lang=c
 *
 * [581] Shortest Unsorted Continuous Subarray
 *
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
 *
 * algorithms
 * Easy (29.68%)
 * Total Accepted:    62.8K
 * Total Submissions: 210.3K
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * Given an integer array, you need to find one continuous subarray that if you
 * only sort this subarray in ascending order, then the whole array will be
 * sorted in ascending order, too.  
 * 
 * You need to find the shortest such subarray and output its length.
 * 
 * Example 1:
 * 
 * Input: [2, 6, 4, 8, 10, 9, 15]
 * Output: 5
 * Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make
 * the whole array sorted in ascending order.
 * 
 * 
 * 
 * Note:
 * 
 * Then length of the input array is in range [1, 10,000].
 * The input array may contain duplicates, so ascending order here means . 
 * 
 * 
 */
int findUnsortedSubarray(int *nums, int numsSize) {
    int start = numsSize, end = 0;
    bool isFirst = true;

    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            end = i;
            if (isFirst) {
                start = i;
                isFirst = false;
            }
        }
    }

    if (isFirst) {
        return 0;
    }

    int tmp = end + 1;
    while (tmp < numsSize - 1 && nums[tmp] == nums[tmp + 1]) {
        tmp++;
    }
    end = tmp;

    tmp = start;
    while (start > 0 && nums[tmp] == nums[tmp - 1]) {
        tmp--;
    }
    start = tmp;

    int min = nums[start], max = nums[end];
    for (int i = start; i <= end; i++) {
        if (min > nums[i]) {
            min = nums[i];
        }
        if (max < nums[i]) {
            max = nums[i];
        }
    }

    for (int i = 0; i < start; i++) {
        if (nums[i] > min) {
            start = i;
            break;
        }
    }

    for (int i = numsSize - 1; i > end; i--) {
        if (nums[i] < max) {
            end = i;
            break;
        }
    }

    return end - start + 1;
}

