/*
 * @lc app=leetcode id=67 lang=c
 *
 * [67] Add Binary
 */

#include "stdio.h"
#include <stdlib.h>

// @lc code=start
char *add(char *a, int lenA, char *b, int lenB) {
    int t = 0;
    char *ret = (char *)malloc(lenA + 2);
    ret[lenA + 1] = '\0';
    ret++;
    int i;
    for (i = 1; i <= lenA; i++) {
        int ca = (int)(a[lenA - i]) - (int)'0';
        int cb;
        if (i > lenB) {
            cb = 0;
        } else {
            cb = (int)(b[lenB - i]) - (int)'0';
        }
        if ((ca + cb + t) == 1) {
            ret[lenA - i] = '1';
            t = 0;
            continue;
        }
        if ((ca + cb + t) == 2) {
            ret[lenA - i] = '0';
            t = 1;
            continue;
        }
        if ((ca + cb + t) == 3) {
            ret[lenA - i] = '1';
            t = 1;
            continue;
        }
        ret[lenA - i] = '0';
    }
    if (t == 0) {
        return ret;
    } else {
        ret--;
        ret[0] = '1';
        return ret;
    }
}

char *addBinary(char *a, char *b) {
    int lenA = 0;
    char *tmpA = a;
    int lenB = 0;
    char *tmpB = b;
    while ((*tmpA) != '\0') {
        lenA++;
        tmpA++;
    }
    while ((*tmpB) != '\0') {
        lenB++;
        tmpB++;
    }
    if (lenA > lenB) {
        return add(a, lenA, b, lenB);
    } else {
        return add(b, lenB, a, lenA);
    }
}
// @lc code=end

int main() {
    printf("%s", addBinary("1111", "1111"));
    return 0;
}