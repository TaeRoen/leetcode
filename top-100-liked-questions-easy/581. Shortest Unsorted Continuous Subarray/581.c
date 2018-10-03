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