int maxSubArray(int *nums, int numsSize)
{
    if (numsSize == 1)
        return nums[0];

    int i = 0;
    while (nums[i] == 0 && i < numsSize)
    {
        i++;
    }
    if (i == numsSize)
        return 0;

    int min_reverse = nums[i] < 0 ? nums[i] : 0;
    int min = min;
    int max = nums[i];
    int max_num = nums[i];

    for (; i < numsSize; i++)
    {
        if (max_num < nums[i])
        {
            max_num = nums[i];
        }
        nums[i] += nums[i - 1];
        if (nums[i] < min_reverse)
        {
            min_reverse = nums[i];
        }
        if (nums[i] > max)
        {
            max = nums[i];
            min = min_reverse;
        }
    }
    if (max != nums[0])
    {
        return max - min;
    }
    else
    {
        return max_num;
    }
}