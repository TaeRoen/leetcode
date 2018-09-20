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