class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        while (slow != fast);
        int slow_two = 0;
        while (true) {
            slow = nums[slow];
            slow_two = nums[slow_two];
            if (slow == slow_two) {
                return slow;
            }
        }
    }
};
