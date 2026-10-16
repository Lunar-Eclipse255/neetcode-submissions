class Solution {
public:
    vector<vector<int>> res;
    vector<int> curr;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(nums, target, 0);
        return res;
    }
    void backtrack(vector<int>& nums, int target, int i) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }
        if (target < 0 || i >= nums.size()) {
            return;
        }
        curr.push_back(nums[i]);
        backtrack(nums, target-nums[i], i);
        curr.pop_back();
        backtrack(nums, target, i+1);

    }
};
