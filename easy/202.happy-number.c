/*
 * @lc app=leetcode id=202 lang=c
 *
 * [202] Happy Number
 */


bool isHappy(int n) {
    if (n == 1) {
        return true;
    }
    if (n <= 4) {
        return false;
    }
    int sum1 = 0;
    while (n != 1) {
        sum1 = 0;
        while (n != 0) {
            int sum = (n % 10) * (n % 10);
            n = n / 10;
            sum1 += sum;
        }
        n = sum1;
        if (n == 4) {
            return false;
        }
    }
    return true;
}


