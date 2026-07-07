class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int max_area = min(height[left], height[right]) * (right - left);
        while (left < right) {
            if (height[left]<=height[right]) {
                left++;
            }
            else {
                right--;
            }
            int area = min(height[left], height[right]) * (right - left);
            if (max_area<area) {
                max_area = area;
            }
        }
        return max_area;
    }
};