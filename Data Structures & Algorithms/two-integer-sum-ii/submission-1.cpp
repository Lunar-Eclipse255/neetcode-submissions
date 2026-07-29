class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        std::unordered_map<int, int> nums;
        for (int i = 0; i < numbers.size(); i++){
            auto result = nums.find(target-numbers[i]);
            if (result == nums.end() || result->first == numbers[i]) {
                nums.insert({numbers[i], i+1});
                continue;
            }
            nums.insert({numbers[i], i});
            if (result->first < numbers[i]) {
                return {result->second, i+1};
            }
            else {
                return {i+1, result->second};
            }
        }
        return {};
    }
};
