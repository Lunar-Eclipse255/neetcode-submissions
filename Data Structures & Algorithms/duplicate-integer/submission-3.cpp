class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> numbers;
        for (int num : nums){
            if (!numbers.insert(num).second) {
                return true;
            }
        }
    return false;
    }
};