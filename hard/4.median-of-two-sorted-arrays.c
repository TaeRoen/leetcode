/*
 * @lc app=leetcode id=4 lang=c
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (25.67%)
 * Total Accepted:    413K
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 * 
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size) {
    int numsSize = nums1Size + nums2Size;
    int *nums = (int *)malloc(sizeof(int) * (numsSize));
    int index1 = 0, index2 = 0;

    for (int i = 0; i < numsSize; i++) {
        if (index1 == nums1Size) {
            nums[i] = nums2[index2];
            index2++;
            continue;
        }
        if (index2 == nums2Size) {
            nums[i] = nums1[index1];
            index1++;
            continue;
        }
        if (nums1[index1] < nums2[index2]) {
            nums[i] = nums1[index1];
            index1++;
        } else {
            nums[i] = nums2[index2];
            index2++;
        }
    }

    if (numsSize % 2 == 0) {
        return ((double)nums[numsSize / 2] + (double)nums[numsSize / 2 - 1]) / 2;
    } else {
        return nums[numsSize / 2];
    }
}

