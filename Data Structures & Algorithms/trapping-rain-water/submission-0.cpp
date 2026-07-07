class Solution {
public:
    int trap(vector<int>& height) {
        int sum=0;
        int left_max = 0;
        int right_max = 0;
        vector<int> left_max_vec;
        vector<int> right_max_vec;
        int n = height.size();
        for (int i = 0; i<n; i++){
            int right_index = n-i-1;
            if (height[i]>left_max){
                left_max=height[i];
            }
            if (height[right_index]>right_max) {
                right_max=height[right_index];
            }
            left_max_vec.push_back(left_max);
            right_max_vec.push_back(right_max);
        }
        reverse(right_max_vec.begin(), right_max_vec.end());
        for (int i = 0; i<n; i++) {
            int add = min(left_max_vec[i], right_max_vec[i]) - height[i];
            if (add < 0){
                add = 0;
            }
            sum+=add;
        }
        return sum;
    }
};