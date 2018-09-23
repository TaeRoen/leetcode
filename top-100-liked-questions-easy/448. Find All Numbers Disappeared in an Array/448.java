class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> res = new ArrayList<>();
        if(nums.length == 0 || nums.length == 1){
            return res;
        }
        int n = nums.length+1;
        for (int i = 0; i < nums.length; i++) {
            nums[nums[i]%n-1] += n;
        }
        for (int i = 0; i < nums.length; i++) {
            if(nums[i] < n ){
                res.add(i+1);
            }
        }
        return res;
    }
}