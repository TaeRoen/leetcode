int power(int x, int rount) {
    for (int i = 0; i < rount; i++) {
        if (x > 0xCCCCCCC) {
            return 0x7FFFFFFF;
        }
        x *= 10;
    }
    return x;
}
int reverse(int x) {
    if (x == 0) {
        return 0;
    }
    while (x % 10 == 0) {
        x /= 10;
    }
    int symbol = x > 0 ? 1 : -1;
    if (symbol == -1) {
        x *= symbol;
        if (x < 0) {
            return 0;
        }
    }
    int bit[32];
    int count = 0;
    int res = 0;
    for (; x != 0; count++) {
        bit[count] = x % 10;
        x /= 10;
    }
    for (int i = 0; i < count; i++) {
        int tmp = power(bit[i], (count - i - 1));
        if (0x7FFFFFFF - res > tmp) {
            res += tmp;
        } else {
            return 0;
        }
    }
    return res * symbol;
}