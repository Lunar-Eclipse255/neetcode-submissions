class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size()+nums2.size();
        int n_2 = n/2;
        const vector<int>* small = nums1.size() < nums2.size() ? &nums1 : &nums2;
        const vector<int>* large = nums1.size() < nums2.size() ? &nums2 : &nums1;
        int left = 0, right = small->size(); 
        while(left<=right) {
            const int mid = left + (right-left)/2;
            const int large_index = n_2 - mid;
            const int small_left = mid > 0 ? (*small)[mid-1] : INT_MIN;
            const int small_right = mid < (int)small->size() ? (*small)[mid] : INT_MAX;
            const int large_left = large_index > 0 ? (*large)[large_index-1] : INT_MIN;
            const int large_right = large_index < (int)large->size() ? (*large)[large_index] : INT_MAX;
            if (small_left <= large_right && large_left <= small_right) {
                if (n%2) {
                    return min(small_right, large_right);
                }
                return ((double) max(small_left, large_left) + min(small_right, large_right))/2;
                
            }
            else if (small_left > large_right) {
                right = mid-1;
            }
            else {
                left = mid +1;
            }
        }
        return -1;
    }
};