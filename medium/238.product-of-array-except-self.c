/*
 * @lc app=leetcode id=238 lang=c
 *
 * [238] Product of Array Except Self
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void productExceptSelf0(int* nums, int* returnNums, int start, int end) {
    if(start == end){
        return;
    }
    if(end - start == 1){
        returnNums[start]*=nums[end];
        returnNums[end]*=nums[start];
        return;
    }
    int left = 1;
    int right = 1;
    int middle = start+(end-start)/2;
    for(int i = start;i<=middle;i++){
        left*=nums[i];
    }
    for(int i = middle+1;i<=end;i++){
        right*=nums[i];
    }
    for(int i = start;i<=middle;i++){
        returnNums[i]*=right;
    }
    for(int i = middle+1;i<=end;i++){
        returnNums[i]*=left;
    }
    productExceptSelf0(nums,returnNums,start,middle);
    productExceptSelf0(nums,returnNums,middle+1,end);
    
}
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* returnNums = (int*)malloc(sizeof(int)*numsSize);
    *returnSize = numsSize;
    for(int i=0;i<numsSize;i++){
        returnNums[i]=1;
    }
    productExceptSelf0(nums,returnNums,0,numsSize-1);
    return returnNums;
}



