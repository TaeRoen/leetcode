class Solution {
    public int numJewelsInStones(String J, String S) {
        boolean jewels[] = new boolean[128];
        for (boolean b: jewels) {
            b = false;
        }
        for (char c : J.toCharArray()) {
            jewels[(int)c] = true;
        }

        int result = 0;
        for (char c : S.toCharArray()) {
            if(jewels[(int)c]){
                result++;
            }
        }
        return result;
    }
}