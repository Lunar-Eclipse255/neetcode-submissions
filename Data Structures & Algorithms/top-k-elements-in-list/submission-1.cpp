class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        vector<pair<int, int>> vector_nums;
        for (int element : nums) {
            map[element]++;
        }
        for (auto& element : map) {
            vector_nums.push_back({element.second, element.first});
        }
        sort(vector_nums.rbegin(), vector_nums.rend());
        vector<int> sol;
        for (int i = 0; i < k; i++) {
            sol.push_back(vector_nums[i].second);
        }
        return sol;
    }
};