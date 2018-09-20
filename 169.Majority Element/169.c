int majorityElement(int *nums, int numsSize) {
    int *elements = (int *)malloc(sizeof(int) * numsSize);
    int *counts = (int *)malloc(sizeof(int) * numsSize);

    int element_count = 0;
    for (int i = 0; i < numsSize; i++) {
        bool isSave = false;
        for (int j = 0; j < element_count; j++) {
            if (elements[j] == nums[i]) {
                isSave = true;
                counts[j]++;
                if (counts[j] > numsSize / 2) {
                    return nums[i];
                }
            }
        }
        if (!isSave) {
            elements[element_count] = nums[i];
            counts[element_count] = 1;
            element_count++;
        }
    }
    return nums[0];
}