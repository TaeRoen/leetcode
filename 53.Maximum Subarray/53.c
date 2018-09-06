int maxSubArray(int *nums, int numsSize) {
    int max = nums[0], tmp_sum = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if(tmp_sum > 0){
            tmp_sum += nums[i];
        }else{
            tmp_sum = nums[i];
        }
        if(max < tmp_sum){
            max = tmp_sum;
        }
    }
    return max;
}