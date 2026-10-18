class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int curr = 0;
        for (int& num : nums) {
            if (curr < 0) {
                curr = 0;
            }
            curr += num;
            max_sum = max(curr, max_sum);
        }
        return max_sum;
    }
};