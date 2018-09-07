class Solution {
    public int singleNumber(int[] nums) {
        if(nums.length == 1){
            return nums[0];
        }
        Arrays.sort(nums);
        for (int i = 1; i < nums.length; i = i + 2) {
            if(nums[i] == nums[i+1]){
                return nums[i-1];
            }
        }
        return nums[nums.length-1];
    }
}