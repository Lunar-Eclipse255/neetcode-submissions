class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        vector<vector<int>> sol;
        for (int i = 0; i<nums.size(); i++) {
            count[nums[i]]--;
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            for (int j= i+1; j<nums.size(); j++) {
                count[nums[j]]--;
                if (j != i+1 && nums[j] == nums[j - 1]) continue;
                    if (count[-(nums[i]+nums[j])] >0 ){
                        sol.push_back({nums[i], nums[j], -(nums[i]+nums[j])});
                    }
            }
            for (int j = i + 1; j < nums.size(); j++) {
                count[nums[j]]++;
            }
        }
        return sol;
    }
};