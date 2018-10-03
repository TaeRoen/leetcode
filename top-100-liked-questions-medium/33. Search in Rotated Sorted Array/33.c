int binarySearch(int *nums, int start_index, int end_index, int target) {
    if (end_index - start_index > 4) {
        int res1 = binarySearch(nums, start_index, start_index + (end_index - start_index) / 2, target);
        int res2 = binarySearch(nums, start_index + (end_index - start_index) / 2 + 1, end_index, target);
        return res1 > res2 ? res1 : res2;
    } else {
        for (int i = start_index; i <= end_index; i++) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }
}

int specialBinarySearch(int *nums, int start_index, int end_index, int target) {
    if (end_index - start_index > 4) {
        int middle_index = start_index + (end_index - start_index) / 2;
        if (nums[middle_index] > nums[0]) {
            if (nums[middle_index] > target) {
                return binarySearch(nums, start_index, middle_index, target);
            } else {
                return specialBinarySearch(nums, start_index, middle_index, target);
            }
        } else {
            if (nums[middle_index] > target) {
                return specialBinarySearch(nums, start_index, middle_index, target);
            } else {
                return binarySearch(nums, start_index, middle_index, target);
            }
        }
    } else {
        for (int i = start_index; i <= end_index; i++) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }
}

int search(int *nums, int numsSize, int target) {
    if (nums[0] < nums[numsSize - 1]) {
        return binarySearch(nums, 0, numsSize - 1, target);
    } else {
        for (int i = 0; i < numsSize; i++) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }
}