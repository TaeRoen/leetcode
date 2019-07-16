/*
 * @lc app=leetcode id=771 lang=c
 *
 * [771] Jewels and Stones
 *
 * https://leetcode.com/problems/jewels-and-stones/description/
 *
 * algorithms
 * Easy (82.76%)
 * Total Accepted:    227.8K
 * Total Submissions: 274.6K
 * Testcase Example:  '"aA"\n"aAAbbbb"'
 *
 * You're given strings J representing the types of stones that are jewels, and
 * S representing the stones you have.  Each character in S is a type of stone
 * you have.  You want to know how many of the stones you have are also
 * jewels.
 * 
 * The letters in J are guaranteed distinct, and all characters in J and S are
 * letters. Letters are case sensitive, so "a" is considered a different type
 * of stone from "A".
 * 
 * Example 1:
 * 
 * 
 * Input: J = "aA", S = "aAAbbbb"
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: J = "z", S = "ZZ"
 * Output: 0
 * 
 * 
 * Note:
 * 
 * 
 * S and J will consist of letters and have length at most 50.
 * The characters in J are distinct.
 * 
 * 
 */
int numJewelsInStones(char* J, char* S) {
    bool jewels[128];
    for (int i = 0; i < 128; i++) {
        jewels[i]=false;
    }
    
    int ret = 0;
    while (*J!='\0'){
        jewels[*J]=true;
        J++;
    }
    while (*S!='\0'){
        if(jewels[*S]){
            ret++;
        }
        S++;
    }
    return ret;
}

