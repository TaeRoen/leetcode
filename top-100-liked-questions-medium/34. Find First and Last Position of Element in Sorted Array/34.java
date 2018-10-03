class Solution {
    private int findStart(int[] nums, int target, int start, int end) {
        while (end >= 0 && nums[end] == target) {
            end--;
        }
        return end + 1;
    }

    private int findEnd(int[] nums, int target, int start, int end) {
        while (start <= end && nums[start] == target) {
            start++;
        }
        return start - 1;
    }

    private int binarySearch(int[] nums, int target, int start, int end) {
        if (end < start) {
            return -1;
        }
        if (end == start) {
            if (nums[start] == target) {
                return start;
            } else {
                return -1;
            }
        }
        int middle = (end - start) / 2 + start;
        if (nums[middle] == target) {
            return middle;
        } else if (nums[middle] > target) {
            return binarySearch(nums, target, start, middle - 1);
        } else {
            return binarySearch(nums, target, middle + 1, end);
        }
    }

    public int[] searchRange(int[] nums, int target) {
        int[] ret = new int[2];
        int retBinary = binarySearch(nums, target, 0, nums.length - 1);
        if (retBinary == -1) {
            ret[0] = -1;
            ret[1] = -1;
        } else {
            ret[0] = findStart(nums, target, 0, retBinary);
            ret[1] = findEnd(nums, target, retBinary, nums.length - 1);
        }
        return ret;
    }
}