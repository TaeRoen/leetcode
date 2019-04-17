/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool isEual(int *a, int *b) {
    for (int i = 0; i < 26; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

int *findAnagrams(char *s, char *p, int *returnSize) {
    int *res = (int *)malloc(sizeof(int) * 20100);
    *returnSize = 0;
    int *p_collect = (int *)malloc(sizeof(int) * 26);
    int *tmp_collect = (int *)malloc(sizeof(int) * 26);

    for (int i = 0; i < 26; i++) {
        p_collect[i] = 0;
        tmp_collect[i] = 0;
    }

    int p_count = 0;
    while (p[p_count] <= 'z' && p[p_count] >= 'a') {
        p_collect[p[p_count] - 'a']++;
        p_count++;
    }

    for (int i = 0; i < p_count; i++) {
        if (s[i] <= 'z' && s[i] >= 'a') {
            tmp_collect[s[i] - 'a']++;
        } else {
            return res;
        }
    }

    int i = 0;
    for (; s[i + p_count] <= 'z' && s[i + p_count] >= 'a'; i++) {
        if (isEual(p_collect, tmp_collect)) {
            res[*returnSize] = i;
            *returnSize++;
        }
        tmp_collect[s[i] - 'a']--;
        tmp_collect[s[i + p_count] - 'a']++;
    }

    if (isEual(p_collect, tmp_collect)) {
        res[*returnSize] = i;
        *returnSize++;
    }

    return res;
}