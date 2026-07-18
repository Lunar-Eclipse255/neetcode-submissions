class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> num_set;
        for (int i = 0; i < nums.size(); i++) {
            auto it = num_set.find(target - nums[i]);
            if (it != num_set.end()) {
                return {it->second, i};
            }
            num_set.insert({nums[i], i});
        }
    }
};
