class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int prev_element = nums[0];
        int length = 1;
        int local_length = 1;
        for (int i = 1; i<nums.size(); i++){
            int current = nums[i];
            if ((current-prev_element)==1) {
                local_length++;
            }
            else if (current==prev_element) {
                continue;
            }
            else {
                length = max(length, local_length);
                local_length = 1;
            }
            prev_element = current;
        }
        length = max(length, local_length);
        return length;
    }
};