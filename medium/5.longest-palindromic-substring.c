/*
 * @lc app=leetcode id=5 lang=c
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start

int palindromeLength(char *s, int size, int a, int b) {
    int bin = 0;
    while (a >= 0 && b < size && s[a] == s[b]) {
        a--;
        b++;
        bin++;
    }
    int res = b - a - 1;
    return res;
}

char *longestPalindrome(char *s) {
    int size = 0;
    char *tmp = s;
    while ((*tmp) != '\0') {
        tmp++;
        size++;
    }
    if (size == 0 || size == 1) {
        return s;
    }
    if (size == 2) {
        if (s[0] == s[1]) {
            return s;
        }
    }

    int max_length = 1;
    int max_start = 0;
    if (s[0] == s[1]) {
        max_length = 2;
    }

    for (int i = 2; i < size; i++) {
        int ret = palindromeLength(s, size, i - 2, i);
        if (ret > max_length) {
            max_length = ret;
            max_start = i - ret / 2 - 1;
        }
        ret = palindromeLength(s, size, i - 1, i);
        if (ret > max_length) {
            max_length = ret;
            max_start = i - ret / 2;
        }
    }
    for (int i = 0; i < max_start; i++) {
        s++;
    }
    s[max_length] = '\0';
    return s;
}
// @lc code=end
