class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pair;
        std::stack<double> time_stack;
        for (int i = 0; i < position.size(); i++) {
            pair.push_back({position[i], speed[i]});
        }
        sort(pair.rbegin(), pair.rend());
        for (auto element: pair) {
            double time = static_cast<double>((target - element.first))/ element.second;
            if (time_stack.empty() || time_stack.top()<time){
                time_stack.push(time);
            }
        }
        return time_stack.size();
    }
};