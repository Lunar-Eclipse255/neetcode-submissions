class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curr_min = 1, curr_max = 1;
        int res = nums[0];
        for (int num : nums) {
            int temp = curr_max * num;
            curr_max = max(max(temp, curr_min * num), num);
            curr_min = min(min(temp, curr_min * num), num);
            res = max(curr_max, res);
        }
        return res;
    }
};
