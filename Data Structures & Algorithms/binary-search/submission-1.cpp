class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size(), value, mid;
        while (left<=right) {
            mid = left + (right - left) / 2;
            value = nums[mid];
            if (value == target) {
                return mid;
            }
            else if (value<target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1;
    }
};
