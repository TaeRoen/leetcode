/*
 * @lc app=leetcode id=35 lang=c
 *
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (40.49%)
 * Total Accepted:    384K
 * Total Submissions: 944.3K
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 * 
 * You may assume no duplicates in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,5,6], 5
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,3,5,6], 2
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1,3,5,6], 7
 * Output: 4
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: [1,3,5,6], 0
 * Output: 0
 * 
 * 
 */
int searchInsert(int* nums, int numsSize, int target) {
    if(numsSize == 0){
        return 0;
    }
    int start = 0;
    int end = numsSize-1;
    while (start < end)
    {
        int index = (start+end)/2;
        if(nums[index] == target){
            return index;
        }
        if(nums[index] > target){
            end = index-1;
        }else {
            start = index+1;
        }
    }
    if(start == end){
        if(nums[start] < target){
            return start + 1;
        }else
        {
            return start;
        }
    }else{
        if(end >= 0 && nums[end] < target){
            return start;
        }else {
            return 0;
        }
        
    }
    
}

