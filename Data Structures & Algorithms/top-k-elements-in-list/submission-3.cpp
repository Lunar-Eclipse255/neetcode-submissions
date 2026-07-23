class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freqs;
        std::vector<std::vector<int>> f(nums.size() + 1);
        std::vector<int> result;
        for (int num : nums) {
            freqs[num]++;
        }
        for (const auto& freq: freqs) {
            f[freq.second].push_back(freq.first);
        }
        for (int i = f.size()-1; i > 0; i--) {
            for (int n : f[i]) {
                result.push_back(n);
                if (result.size() == k){
                    return result;
                }
            }
        }
        return result;
    }
};
