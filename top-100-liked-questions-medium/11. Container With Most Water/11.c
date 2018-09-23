int maxAreaInZone(int *height, int heightSize, int start, int end) {
    int current = (end - start) * (height[start] < height[end] ? height[start] : height[end]);
    if (end - start == 1) {
        return current;
    }
    if (height[start] > height[end]) {
        for (int i = end - 1; i > start; i--) {
            int tmp = (i - start) * (height[start] < height[i] ? height[start] : height[i]);
            if (tmp > current) {
                return maxAreaInZone(height, heightSize, start, i);
            }
        }

    } else {
        for (int i = start + 1; i < end; i++) {
            int tmp = (end - i) * (height[i] < height[end] ? height[i] : height[end]);
            if (tmp > current) {
                return maxAreaInZone(height, heightSize, i, end);
            }
        }
    }
    return current;
}

int maxArea(int *height, int heightSize) {
    return maxAreaInZone(height, heightSize, 0, heightSize - 1);
}