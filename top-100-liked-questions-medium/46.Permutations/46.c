/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int **permute(int *nums, int numsSize, int *returnSize)
{
    *returnSize = 1;

    for (int i = 1; i <= numsSize; i++)
    {
        *returnSize *= i;
    }

    int **res = (int **)malloc(sizeof(int) * *returnSize);

    for (int i = 0; i < *returnSize; i++)
    {
        res[i] = (int *)malloc(sizeof(int) * numsSize);
    }

    return (int **)res;
}