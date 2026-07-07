class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_val = 0, min_val=prices[0];
        for (int price: prices) {
            max_val = max(max_val, price-min_val);
            min_val = min (price, min_val);
        }
        return max_val;
    }
};