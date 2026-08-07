class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest = prices[0];
        int max_profit = 0;
        for (int price: prices) {
            lowest = min(lowest, price);
            max_profit = max(max_profit, (price-lowest));
        }
        return max_profit;
    }
};
