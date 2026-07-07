class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0, right = 1;
        int max_val = 0;
        while (right<prices.size()) {
            int left_val = prices[left], right_val=prices[right];
            if (right_val>left_val) {
                max_val = max(right_val-left_val, max_val);
            }
            else {
                left=right;
            }
            right++;
        }
        return max_val;
    }
};