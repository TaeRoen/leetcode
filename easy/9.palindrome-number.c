/*
 * @lc app=leetcode id=9 lang=c
 *
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (42.20%)
 * Total Accepted:    524.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '121'
 *
 * Determine whether an integer is a palindrome. An integer is a palindrome
 * when it reads the same backward as forward.
 * 
 * Example 1:
 * 
 * 
 * Input: 121
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 * 
 * 
 * Follow up:
 * 
 * Coud you solve it without converting the integer to a string?
 * 
 */
bool isPalindrome(int x) {
    if ( x < 0) {
        return false;
    }
    if (x < 10) {
        return true;
    }
    int res[10];
    int j = 0;
    while(x > 0){
        res[j] = x%10;
        x/=10;
        j++;
    }
    j--;
    int i = 0;
    while(i < j){
        if(res[i] != res[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

