class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<pair<int, int>> height_stack;
        int max_area = 0;
        for (int i = 0; i < heights.size(); i++) {
            int start = i; 
            while (!height_stack.empty() && height_stack.top().first > heights[i]) {
                pair<int, int> top = height_stack.top();
                height_stack.pop();
                max_area = std::max(max_area,
                                    top.first * (i - top.second));
                start = top.second;
            }

            height_stack.push({heights[i], start});
        }
        while (!height_stack.empty()) {
            pair<int, int> top = height_stack.top();
            height_stack.pop();
            max_area = std::max(max_area,
                                top.first * ((int) heights.size() - top.second));
        }

        return max_area;
    }
};