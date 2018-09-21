int maxProfit(int *prices, int pricesSize) {
    int *max_prices = (int *)malloc(sizeof(int) * pricesSize);

    int tmp = prices[pricesSize - 1];
    max_prices[pricesSize - 1] = prices[pricesSize - 1];
    for (int i = pricesSize - 2; i >= 0; i--) {

        if (prices[i] > tmp) {
            tmp = prices[i];
        }
        max_prices[i] = tmp;
    }
    tmp = 0;

    for (int i = 0; i < pricesSize - 1; i++) {
        if (max_prices[i] - prices[i] > tmp) {
            tmp = max_prices[i] - prices[i];
        }
    }
    return tmp;
}