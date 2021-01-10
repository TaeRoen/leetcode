/*
 * @lc app=leetcode id=11 lang=c
 *
 * [11] Container With Most Water
 */

// @lc code=start


int maxArea(int *height, int heightSize) {
    int *ret = (int *)malloc(sizeof(int) * (heightSize - 1));
    int maxHeight = height[0];
    for (int i = 0; i < heightSize - 1; i++) {
        int max = 0;
        if (height[i] < maxHeight) {
            ret[i] = 0;
            continue;
        } else {
            maxHeight = height[i];
        }

        for (int j = i + 1; j < heightSize; j++) {
            int size = (j - i) * (height[i] > height[j] ? height[j] : height[i]);
            if (size > max) {
                max = size;
            }
            ret[i] = max;
        }
    }
    int maxArea = 0;
    for (int i = 0; i < heightSize - 1; i++) {
        if (ret[i] > maxArea) {
            maxArea = ret[i];
        }
    }
    return maxArea;
}
// @lc code=end
