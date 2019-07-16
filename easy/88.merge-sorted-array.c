/*
 * @lc app=leetcode id=88 lang=c
 *
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (34.98%)
 * Total Accepted:    349.5K
 * Total Submissions: 988.8K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 * 
 * Note:
 * 
 * 
 * The number of elements initialized in nums1 and nums2 are m and n
 * respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2.
 * 
 * 
 * Example:
 * 
 * 
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * Output: [1,2,2,3,5,6]
 * 
 * 
 */
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i=m+n-1;
    m--;
    n--;
    while(i!=0 && m>=0 && n>=0){
        if(nums1[m]>nums2[n]){
            nums1[i] = nums1[m];
            m--;
        }else{
            nums1[i] = nums2[n];
            n--;
        }
        i--;
    }
    if(n>=0){
        for(int j=0;j<=n;j++){
            nums1[j]=nums2[j];
        }
    }
}

