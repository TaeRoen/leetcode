/*
 * @lc app=leetcode id=58 lang=c
 *
 * [58] Length of Last Word
 */

// @lc code=start
#include "stdio.h"

int lengthOfLastWord(char *s) {
    int ret = 0;
    int real = 0;
    while (*s != '\0') {
        if (*s != ' ') {
            ret++;
            real = ret;
        } else {
            ret = 0;
        }
        s++;
    }
    return real;
}
// @lc code=end

int main() {
    printf("%d", lengthOfLastWord("abc"));
}