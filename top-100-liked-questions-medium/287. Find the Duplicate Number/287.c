int search(int *nums, int numsSize, int min, int max)
{
    int res = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] >= min && nums[i] <= max)
        {
            res++;
        }
    }
    if (res <= (max - min + 1))
    {
        return 0;
    }
    else
    {
        if (min == max)
        {
            return min;
        }
        else
        {
            int res1 = search(nums, numsSize, min, (max - min) / 2 + min);
            int res2 = search(nums, numsSize, (max - min) / 2 + min + 1, max);
            return res1 > res2 ? res1 : res2;
        }
    }
}

int findDuplicate(int *nums, int numsSize)
{
    int res1 = search(nums, numsSize, 1, (numsSize - 1) / 2);
    int res2 = search(nums, numsSize, (numsSize - 1) / 2 + 1, numsSize - 1);
    return res1 > res2 ? res1 : res2;
}