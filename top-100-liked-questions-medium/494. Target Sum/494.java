import java.util.HashMap;
import java.util.HashSet;

class Solution {
    public int findTargetSumWays(int[] nums, int S) {
        if (nums.length == 0) {
            return 0;
        }
        HashMap<Integer, Integer> map = new HashMap<>();
        HashMap<Integer, Integer> workMap;
        HashSet<Integer> workSet = new HashSet<>();
        if (nums[0] == 0) {
            map.put(num[0], 2);
        } else {
            map.put(num[0], 1);
            map.put((0 - num[0]), 1);
        }
        for (int j = 1; j < num.length; j++) {
            workMap = (HashMap) map.clone();
            map.clear();
            workSet.clear();
            for (int i : workMap.keySet()) {
                workSet.add(i + nums[j]);
                workSet.add(i - nums[j]);
            }
            for (int i : workSet) {
                if (workMap.get(i + nums[j]) == 0) {
                    workMap.put(i + nums[j], 0);
                }
                if (workMap.get(i - nums[j]) == 0) {
                    workMap.put(i - nums[j], 0);
                }
                map.put(i, workMap.get(i + nums[j]) + workMap.get(i - nums[j]));
            }
        }
        if (map.get(S) != null) {
            return map.get(S);
        }
        return 0;
    }
}