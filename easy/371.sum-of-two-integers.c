/*
 * @lc app=leetcode id=371 lang=c
 *
 * [371] Sum of Two Integers
 */


int getSum(int a, int b) {
    int c = a^b;
    int d = (unsigned int)(a&b)<<1;
    if(d != 0){
        return getSum(c,d);
    }
    return c;
}


