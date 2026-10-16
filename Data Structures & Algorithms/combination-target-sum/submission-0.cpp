class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        backtrack(nums, target, 0);
        return res;
    }

    void backtrack(vector<int>& nums, int target, int i) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        if (target < 0 || i >= nums.size()) {
            return;
        }

        cur.push_back(nums[i]);
        backtrack(nums, target - nums[i], i);
        cur.pop_back();
        backtrack(nums, target, i + 1);
    }
};