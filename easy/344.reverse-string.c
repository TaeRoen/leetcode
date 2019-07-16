/*
 * @lc app=leetcode id=344 lang=c
 *
 * [344] Reverse String
 */


void reverseString(char* s, int sSize) {
    int i = 0,j=sSize - 1;
    char tmp;
    while(i<=j){
        tmp = s[j];
        s[j] = s[i];
        s[i] = tmp;
        i++;
        j--;
    }
}



