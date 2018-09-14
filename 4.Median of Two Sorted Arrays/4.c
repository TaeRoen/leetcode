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