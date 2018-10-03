int maxProfit(int *prices, int pricesSize) {
    if (pricesSize < 2) {
        return 0;
    }
    int *buys = (int *)malloc(sizeof(int) * pricesSize);
    int *sells = (int *)malloc(sizeof(int) * pricesSize);
    sells[0] = 0;
    sells[1] = prices[1] - prices[0] > 0 ? prices[1] - prices[0] : 0;
    buys[0] = 0 - prices[0];
    buys[1] = prices[0] > prices[1] ? 0-prices[1]:0-prices[0];

    for (int i = 2; i < pricesSize; i++) {
        sells[i] = sells[i - 1] > buys[i - 1] + prices[i] ? sells[i - 1] : buys[i - 1] + prices[i];
        buys[i] = buys[i - 1] > sells[i - 2] - prices[i] ? buys[i - 1] : sells[i - 2] - prices[i];
    }
    return sells[pricesSize - 1];
}