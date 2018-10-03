void sortColors(int *nums, int numsSize) {
    int p0 = 0, p1 = 0, p2 = 0;
    for (int i = 0; i < numsSize && (p0 == 0 || p1 == 0 || p2 == 0); i++) {
        if (nums[i] == 0) {
            p0++;
        }
        if (nums[i] == 1) {
            p1++;
        }
        if (nums[i] == 2) {
            p2++;
        }
    }
    int start = p0 + p1 + p2;
    for (int i = 0; i < p0; i++) {
        nums[i] = 0;
    }
    for (int i = p0; i < p0 + p1; i++) {
        nums[i] = 1;
    }
    for (int i = p0 + p1; i < p0 + p1 + p2; i++) {
        nums[i] = 2;
    }
    p2 = p0 + p1;
    p1 = p0;
    for (int i = start; i < numsSize; i++) {
        if (nums[i] == 0) {
            nums[p1] = 0;
            p1++;
            nums[p2] = 1;
            p2++;
            nums[i] = 2;
        }
        if (nums[i] == 1) {
            nums[p2] = 1;
            p2++;
            nums[i] = 2;
        }
    }
}