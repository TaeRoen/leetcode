import java.util.ArrayList;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        byte[] bs = s.getBytes();
        if (bs.length == 0) {
            return 0;
        }
        if (bs.length == 1) {
            return 1;
        }
        int[] res = new int[bs.length];
        res[0] = 1;
        int start = 0;
        for (int i = 1; i < bs.length; i++) {
            boolean isRepeat = false;
            for (int j = start; j < i; j++) {
                if (bs[j] == bs[i]) {
                    start = j + 1;
                    res[i] = i - start + 1;
                    isRepeat = true;
                    break;
                }
            }
            if (!isRepeat) {
                res[i] = res[i - 1] + 1;
            }
        }
        int max = 1;
        for (int i : res) {
            if (max < i) {
                max = i;
            }
        }
        return max;
    }
}