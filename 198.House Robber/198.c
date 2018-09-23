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