class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size()-1;
        int sol = nums[0];
        while (left<=right) {
            if (nums[left]<nums[right]) {
                sol = min(sol, nums[left]);
                break;
            }
            int mid = left + (right-left)/2;
            sol = min(sol, nums[mid]);
            if (nums[mid]>=nums[left]) {
                left = mid +1;
            }
            else {
                right = mid-1;
            }
        }
        return sol;
    }
};
