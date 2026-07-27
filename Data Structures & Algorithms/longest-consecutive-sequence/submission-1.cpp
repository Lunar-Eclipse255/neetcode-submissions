class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> seq(nums.begin(), nums.end());
        int longest = 0;
        for (int num : nums) {
            seq.insert(num);
            int len = 0;
            if (seq.count(num-1)) {
                continue;
            }
            int curr = num-1;
            while (seq.count(++curr)) {
                len++;
            }
            longest = max(longest, len);
        }
        return longest;
    }
};
