class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int left_val = nums[left];
            int mid_val = nums[mid];
            int right_val = nums[right];
            if (mid_val == target) {
                return mid;
            }
            if (left_val <= mid_val) {
                if (left_val < target && target < mid_val) {
                    right = mid-1;
                }
                else if (left_val == target){
                    return left;
                }
                else {
                    left = mid+1;
                }
            }
            else {
                if (mid_val < target && target <= right_val) {
                    left = mid+1;
                }
                else if (right_val == target){
                    return right;
                }
                else {
                    right = mid-1;
                }
            }
        }
        return -1;
    }
};