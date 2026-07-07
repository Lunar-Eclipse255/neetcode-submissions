class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<pair<int, int>> temps;
        vector<int> sol(temperatures.size(), 0);
        for (int i=0; i < temperatures.size(); i++) {
            int t = temperatures[i];
            while (!temps.empty() && t > temps.top().first) {
                auto top = temps.top();
                temps.pop();
                sol[top.second] = i - top.second;
            }
            temps.push({t, i});
        }
        return sol;
    }
};
