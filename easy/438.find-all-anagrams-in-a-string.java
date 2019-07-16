/*
 * @lc app=leetcode id=438 lang=java
 *
 * [438] Find All Anagrams in a String
 */
class Solution {
    public boolean isEqual(int[] a,int[] b){
        for(int i = 0;i<26;i++){
            if(a[i]!=b[i]){
                return false;
            }
        }
        return true;
    }
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> res = new ArrayList<>();
        int[] p_status = new int[26];
        int[] s_status = new int[26];
        for(char c:p.toCharArray()){
            p_status[(int)c - (int)'a']++;
        }
        if(s.length() < p.length()){
            return res;
        }
        char[] ss = s.toCharArray();
        for (int i = 0; i < p.length(); i++) {
            s_status[(int)(ss[i]) - (int)'a']++;
        }
        for(int i = 0;i<s.length()-p.length();i++){
            if(isEqual(p_status, s_status)){
                res.add(i);
            }
            s_status[(int)(ss[i+p.length()]) - (int)'a']++;
            s_status[(int)(ss[i]) - (int)'a']--;
        }
        if(isEqual(p_status, s_status)){
            res.add(s.length()-p.length());
        }
        return res;
    }
}

